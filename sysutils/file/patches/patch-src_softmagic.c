$NetBSD: patch-src_softmagic.c,v 1.4 2019/03/16 09:02:41 bsiegert Exp $

Fix functionality under NetBSD-current after format check change
https://mail-index.netbsd.org/source-changes/2017/12/11/msg090400.html

fix PR/62: spinpx: limit size of file_printable.  (CVE-2019-8904)

https://bugs.astron.com/view.php?id=62
https://github.com/file/file/commit/d65781527c8134a1202b2649695d48d5701ac60b

--- src/softmagic.c.orig	2017-07-21 10:29:00.000000000 +0000
+++ src/softmagic.c
@@ -121,6 +121,8 @@ private const char * __attribute__((__fo
 file_fmtcheck(struct magic_set *ms, const struct magic *m, const char *def,
 	const char *file, size_t line)
 {
+	if (strchr(m->desc, '%') == NULL)
+		return m->desc;
 	const char *ptr = fmtcheck(m->desc, def);
 	if (ptr == def)
 		file_magerror(ms,
@@ -546,8 +548,8 @@ mprint(struct magic_set *ms, struct magi
   	case FILE_LESTRING16:
 		if (m->reln == '=' || m->reln == '!') {
 			if (file_printf(ms, F(ms, m, "%s"), 
-			    file_printable(sbuf, sizeof(sbuf), m->value.s))
-			    == -1)
+			    file_printable(sbuf, sizeof(sbuf), m->value.s,
+			    sizeof(m->value.s))) == -1)
 				return -1;
 			t = ms->offset + m->vallen;
 		}
@@ -574,7 +576,8 @@ mprint(struct magic_set *ms, struct magi
 			}
 
 			if (file_printf(ms, F(ms, m, "%s"),
-			    file_printable(sbuf, sizeof(sbuf), str)) == -1)
+			    file_printable(sbuf, sizeof(sbuf), str,
+				sizeof(p->s) - (str - p->s))) == -1)
 				return -1;
 
 			if (m->type == FILE_PSTRING)
@@ -680,7 +683,7 @@ mprint(struct magic_set *ms, struct magi
 			return -1;
 		}
 		rval = file_printf(ms, F(ms, m, "%s"),
-		    file_printable(sbuf, sizeof(sbuf), cp));
+		    file_printable(sbuf, sizeof(sbuf), cp, ms->search.rm_len));
 		free(cp);
 
 		if (rval == -1)
@@ -707,7 +710,8 @@ mprint(struct magic_set *ms, struct magi
 		break;
 	case FILE_DER:
 		if (file_printf(ms, F(ms, m, "%s"), 
-		    file_printable(sbuf, sizeof(sbuf), ms->ms_value.s)) == -1)
+		    file_printable(sbuf, sizeof(sbuf), ms->ms_value.s,
+			sizeof(ms->ms_value.s))) == -1)
 			return -1;
 		t = ms->offset;
 		break;
@@ -1383,38 +1387,64 @@ mget(struct magic_set *ms, const unsigne
 	if (m->flag & INDIR) {
 		intmax_t off = m->in_offset;
 		const int sgn = m->in_op & FILE_OPSIGNED;
-		if (m->in_op & FILE_OPINDIRECT) {
-			const union VALUETYPE *q = CAST(const union VALUETYPE *,
-			    ((const void *)(s + offset + off)));
-			if (OFFSET_OOB(nbytes, offset + off, sizeof(*q)))
-				return 0;
-			switch (cvt_flip(m->in_type, flip)) {
-			case FILE_BYTE:
-				off = SEXT(sgn,8,q->b);
-				break;
-			case FILE_SHORT:
-				off = SEXT(sgn,16,q->h);
-				break;
-			case FILE_BESHORT:
-				off = SEXT(sgn,16,BE16(q));
-				break;
-			case FILE_LESHORT:
-				off = SEXT(sgn,16,LE16(q));
-				break;
-			case FILE_LONG:
-				off = SEXT(sgn,32,q->l);
-				break;
-			case FILE_BELONG:
-			case FILE_BEID3:
-				off = SEXT(sgn,32,BE32(q));
-				break;
-			case FILE_LEID3:
-			case FILE_LELONG:
-				off = SEXT(sgn,32,LE32(q));
-				break;
-			case FILE_MELONG:
-				off = SEXT(sgn,32,ME32(q));
-				break;
+ 		if (m->in_op & FILE_OPINDIRECT) {
+ 			const union VALUETYPE *q = CAST(const union VALUETYPE *,
+ 			    ((const void *)(s + offset + off)));
+ 			switch (cvt_flip(m->in_type, flip)) {
+ 			case FILE_BYTE:
+				if (OFFSET_OOB(nbytes, offset + off, 1))
+					return 0;
+ 				off = SEXT(sgn,8,q->b);
+ 				break;
+ 			case FILE_SHORT:
+				if (OFFSET_OOB(nbytes, offset + off, 2))
+					return 0;
+ 				off = SEXT(sgn,16,q->h);
+ 				break;
+ 			case FILE_BESHORT:
+				if (OFFSET_OOB(nbytes, offset + off, 2))
+					return 0;
+ 				off = SEXT(sgn,16,BE16(q));
+ 				break;
+ 			case FILE_LESHORT:
+				if (OFFSET_OOB(nbytes, offset + off, 2))
+					return 0;
+ 				off = SEXT(sgn,16,LE16(q));
+ 				break;
+ 			case FILE_LONG:
+				if (OFFSET_OOB(nbytes, offset + off, 4))
+					return 0;
+ 				off = SEXT(sgn,32,q->l);
+ 				break;
+ 			case FILE_BELONG:
+ 			case FILE_BEID3:
+				if (OFFSET_OOB(nbytes, offset + off, 4))
+					return 0;
+ 				off = SEXT(sgn,32,BE32(q));
+ 				break;
+ 			case FILE_LEID3:
+ 			case FILE_LELONG:
+				if (OFFSET_OOB(nbytes, offset + off, 4))
+					return 0;
+ 				off = SEXT(sgn,32,LE32(q));
+ 				break;
+ 			case FILE_MELONG:
+				if (OFFSET_OOB(nbytes, offset + off, 4))
+					return 0;
+ 				off = SEXT(sgn,32,ME32(q));
+ 				break;
+ 			case FILE_BEQUAD:
+				if (OFFSET_OOB(nbytes, offset + off, 8))
+					return 0;
+ 				off = SEXT(sgn,64,BE64(q));
+ 				break;
+ 			case FILE_LEQUAD:
+				if (OFFSET_OOB(nbytes, offset + off, 8))
+					return 0;
+ 				off = SEXT(sgn,64,LE64(q));
+ 				break;
+ 			default:
+                               abort();
 			}
 			if ((ms->flags & MAGIC_DEBUG) != 0)
 				fprintf(stderr, "indirect offs=%jd\n", off);
