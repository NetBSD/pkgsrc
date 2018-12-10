$NetBSD: patch-src_pl-rsort.c,v 1.1 2018/12/10 14:59:50 leot Exp $

Use FreeBSD qsort_r(3) if not available instead of using nested
functions.

--- src/pl-rsort.c.orig	2018-01-12 12:04:38.000000000 +0000
+++ src/pl-rsort.c
@@ -65,43 +65,177 @@ from pl-list.c.
 
 #if !defined(HAVE_QSORT_R) && !defined(HAVE_QSORT_S)
 
-#ifdef QSORT_R_WITH_NESTED_FUNCTIONS
+/*-
+ * SPDX-License-Identifier: BSD-3-Clause
+ *
+ * Copyright (c) 1992, 1993
+ *	The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+typedef int		 cmp_t(void *, const void *, const void *);
+static inline char	*med3(char *, char *, char *, cmp_t *, void *);
+
+#define	MIN(a, b)	((a) < (b) ? a : b)
+
+/*
+ * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
+ */
 
-void
-sort_r(void *base, size_t nel, size_t width,
-       int (*compar)(const void *a1, const void *a2, void *aarg), void *arg)
-{ int nested_cmp(const void *a, const void *b)
-  {
-    return compar(a, b, arg);
-  }
+static inline void
+swapfunc(char *a, char *b, size_t es)
+{
+	char t;
 
-  qsort(base, nel, width, nested_cmp);
+	do {
+		t = *a;
+		*a++ = *b;
+		*b++ = t;
+	} while (--es > 0);
 }
 
-#else
+#define	vecswap(a, b, n)				\
+	if ((n) > 0) swapfunc(a, b, n)
 
-static void *sort_r_ctx;
-static int (*sort_r_compar)(const void *a1, const void *a2, void *aarg);
+#define	CMP(t, x, y) (cmp((t), (x), (y)))
 
-int
-nested_cmp(const void *a, const void *b)
-{ return (*sort_r_compar)(a, b, sort_r_ctx);
+static inline char *
+med3(char *a, char *b, char *c, cmp_t *cmp, void *thunk
+)
+{
+	return CMP(thunk, a, b) < 0 ?
+	       (CMP(thunk, b, c) < 0 ? b : (CMP(thunk, a, c) < 0 ? c : a ))
+	      :(CMP(thunk, b, c) > 0 ? b : (CMP(thunk, a, c) < 0 ? a : c ));
 }
 
 void
-sort_r(void *base, size_t nel, size_t width,
-       int (*compar)(const void *a1, const void *a2, void *aarg), void *arg)
-{ PL_LOCK(L_SORTR);
-  sort_r_ctx = arg;
-  sort_r_compar = compar;
-
-  qsort(base, nel, width, nested_cmp);
-  PL_UNLOCK(L_SORTR);
+qsort_r(void *a, size_t n, size_t es, void *thunk, cmp_t *cmp)
+{
+	char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
+	size_t d1, d2;
+	int cmp_result;
+	int swap_cnt;
+
+loop:
+	swap_cnt = 0;
+	if (n < 7) {
+		for (pm = (char *)a + es; pm < (char *)a + n * es; pm += es)
+			for (pl = pm; 
+			     pl > (char *)a && CMP(thunk, pl - es, pl) > 0;
+			     pl -= es)
+				swapfunc(pl, pl - es, es);
+		return;
+	}
+	pm = (char *)a + (n / 2) * es;
+	if (n > 7) {
+		pl = a;
+		pn = (char *)a + (n - 1) * es;
+		if (n > 40) {
+			size_t d = (n / 8) * es;
+
+			pl = med3(pl, pl + d, pl + 2 * d, cmp, thunk);
+			pm = med3(pm - d, pm, pm + d, cmp, thunk);
+			pn = med3(pn - 2 * d, pn - d, pn, cmp, thunk);
+		}
+		pm = med3(pl, pm, pn, cmp, thunk);
+	}
+	swapfunc(a, pm, es);
+	pa = pb = (char *)a + es;
+
+	pc = pd = (char *)a + (n - 1) * es;
+	for (;;) {
+		while (pb <= pc && (cmp_result = CMP(thunk, pb, a)) <= 0) {
+			if (cmp_result == 0) {
+				swap_cnt = 1;
+				swapfunc(pa, pb, es);
+				pa += es;
+			}
+			pb += es;
+		}
+		while (pb <= pc && (cmp_result = CMP(thunk, pc, a)) >= 0) {
+			if (cmp_result == 0) {
+				swap_cnt = 1;
+				swapfunc(pc, pd, es);
+				pd -= es;
+			}
+			pc -= es;
+		}
+		if (pb > pc)
+			break;
+		swapfunc(pb, pc, es);
+		swap_cnt = 1;
+		pb += es;
+		pc -= es;
+	}
+	if (swap_cnt == 0) {  /* Switch to insertion sort */
+		for (pm = (char *)a + es; pm < (char *)a + n * es; pm += es)
+			for (pl = pm; 
+			     pl > (char *)a && CMP(thunk, pl - es, pl) > 0;
+			     pl -= es)
+				swapfunc(pl, pl - es, es);
+		return;
+	}
+
+	pn = (char *)a + n * es;
+	d1 = MIN(pa - (char *)a, pb - pa);
+	vecswap(a, pb - d1, d1);
+	d1 = MIN(pd - pc, pn - pd - es);
+	vecswap(pb, pn - d1, d1);
+
+	d1 = pb - pa;
+	d2 = pd - pc;
+	if (d1 <= d2) {
+		/* Recurse on left partition, then iterate on right partition */
+		if (d1 > es) {
+			qsort_r(a, d1 / es, es, thunk, cmp);
+		}
+		if (d2 > es) {
+			/* Iterate rather than recurse to save stack space */
+			/* qsort(pn - d2, d2 / es, es, cmp); */
+			a = pn - d2;
+			n = d2 / es;
+			goto loop;
+		}
+	} else {
+		/* Recurse on right partition, then iterate on left partition */
+		if (d2 > es) {
+			qsort_r(pn - d2, d2 / es, es, thunk, cmp);
+		}
+		if (d1 > es) {
+			/* Iterate rather than recurse to save stack space */
+			/* qsort(a, d1 / es, es, cmp); */
+			n = d1 / es;
+			goto loop;
+		}
+	}
 }
 
-#endif
+#define HAVE_QSORT_R
 
-#else /*HAVE_QSORT_R|HAVE_QSORT_S*/
+#endif /* !defined(HAVE_QSORT_R) && !defined(HAVE_QSORT_S) */
 
 #ifndef QSORT_R_GNU
 struct sort_r_data
@@ -132,6 +266,3 @@ sort_r(void *base, size_t nel, size_t wi
     qsort_s(base, nel, width, &sort_r_arg_swap, &tmp);
 #endif
 }
-
-#endif /*HAVE_QSORT_R|HAVE_QSORT_S*/
-
