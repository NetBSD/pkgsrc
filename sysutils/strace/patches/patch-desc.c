$NetBSD: patch-desc.c,v 1.1 2019/10/06 17:45:50 christos Exp $

--- desc.c.orig	2007-01-15 15:25:52.000000000 -0500
+++ desc.c	2019-10-06 13:19:12.944039233 -0400
@@ -425,14 +425,14 @@
 	return 0;
 }
 
-#if defined(ALPHA) || defined(FREEBSD) || defined(SUNOS4)
+#if defined(ALPHA) || defined(ALLBSD) || defined(SUNOS4)
 int
 sys_getdtablesize(tcp)
 struct tcb *tcp;
 {
 	return 0;
 }
-#endif /* ALPHA || FREEBSD || SUNOS4 */
+#endif /* ALPHA || ALLBSD || SUNOS4 */
 
 static int
 decode_select(struct tcb *tcp, long *args, enum bitness_t bitness)
@@ -498,7 +498,7 @@
 		outstr[0] = '\0';
 		for (i = 0; i < 3; i++) {
 			int first = 1;
-			char str[20];
+			char str[64];
 
 			tcp->auxstr = outstr;
 			arg = args[i+1];
@@ -508,7 +508,8 @@
 			for (j = 0; j < args[0]; j++) {
 				if (FD_ISSET(j, fds)) {
 					if (first) {
-						sprintf(str, "%s%s [%u", sep,
+						snprintf(str, sizeof(str),
+							"%s%s [%u", sep,
 							i == 0 ? "in" :
 							i == 1 ? "out" :
 							"except", j);
@@ -516,7 +517,8 @@
 						sep = ", ";
 					}
 					else
-						sprintf(str, " %u", j);
+						snprintf(str, sizeof(str),
+							" %u", j);
 					cumlen += strlen(str);
 					if (cumlen < sizeof(outstr))
 						strcat(outstr, str);
