$NetBSD: patch-argp-fmtstream.c,v 1.2 2024/08/06 18:49:16 riastradh Exp $

Avoid ctype(3) abuse.

--- argp-fmtstream.c.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp-fmtstream.c
@@ -206,7 +206,7 @@ __argp_fmtstream_update (argp_fmtstream_
 	  int i;
 
 	  p = buf + (r + 1 - fs->point_col);
-	  while (p >= buf && !isblank (*p))
+	  while (p >= buf && !isblank ((unsigned char) *p))
 	    --p;
 	  nextline = p + 1;	/* This will begin the next line.  */
 
@@ -216,7 +216,7 @@ __argp_fmtstream_update (argp_fmtstream_
 	      if (p >= buf)
 		do
 		  --p;
-		while (p >= buf && isblank (*p));
+		while (p >= buf && isblank ((unsigned char) *p));
 	      nl = p + 1;	/* The newline will replace the first blank. */
 	    }
 	  else
@@ -227,7 +227,7 @@ __argp_fmtstream_update (argp_fmtstream_
 	      /* Find the end of the long word.  */
 	      do
 		++p;
-	      while (p < nl && !isblank (*p));
+	      while (p < nl && !isblank ((unsigned char) *p));
 	      if (p == nl)
 		{
 		  /* It already ends a line.  No fussing required.  */
@@ -240,7 +240,7 @@ __argp_fmtstream_update (argp_fmtstream_
 	      /* Swallow separating blanks.  */
 	      do
 		++p;
-	      while (isblank (*p));
+	      while (isblank ((unsigned char) *p));
 	      /* The next line will start here.  */
 	      nextline = p;
 	    }
@@ -389,6 +389,7 @@ __argp_fmtstream_printf (struct argp_fmt
 weak_alias (__argp_fmtstream_printf, argp_fmtstream_printf)
 #endif
 
+#if __STDC_VERSION__ - 199900L < 1
 /* Duplicate the inline definitions in argp-fmtstream.h, for compilers
  * that don't do inlining. */
 size_t
@@ -471,5 +472,6 @@ __argp_fmtstream_point (argp_fmtstream_t
     __argp_fmtstream_update (__fs);
   return __fs->point_col >= 0 ? __fs->point_col : 0;
 }
+#endif
 
 #endif /* !ARGP_FMTSTREAM_USE_LINEWRAP */
