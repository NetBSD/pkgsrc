$NetBSD: patch-ed.inputl.c,v 1.1 2017/02/17 19:21:44 he Exp $

Add fix from upstream: Unfortunately the AsciiOnly reversion causes
a SEGV because *ch is used to index in the command array, and now contains
INVALID_BYTE.  Reproduce error with:
  env -i ./tcsh
  <meta>b

--- ed.inputl.c.orig	2012-10-19 15:23:32.000000000 +0000
+++ ed.inputl.c
@@ -800,13 +800,17 @@ GetNextChar(Char *cp)
 		return -1;
 	    }
 	}
-	cbp++;
-	if (normal_mbtowc(cp, cbuf, cbp) == -1) {
-	    reset_mbtowc();
-	    if (cbp < MB_CUR_MAX)
-		continue; /* Maybe a partial character */
-	    /* And drop the following bytes, if any */
-	    *cp = (unsigned char)*cbuf | INVALID_BYTE;
+	if (AsciiOnly) {
+	    *cp = (unsigned char)*cbuf;
+	} else {
+	    cbp++;
+	    if (normal_mbtowc(cp, cbuf, cbp) == -1) {
+		reset_mbtowc();
+		if (cbp < MB_CUR_MAX)
+		    continue; /* Maybe a partial character */
+		/* And drop the following bytes, if any */
+		*cp = (unsigned char)*cbuf | INVALID_BYTE;
+	    }
 	}
 	break;
     }
