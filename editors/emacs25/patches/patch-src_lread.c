$NetBSD: patch-src_lread.c,v 1.1 2018/03/21 08:48:15 maya Exp $

Handle NAN not existing (VAX)

--- src/lread.c.orig	2017-04-14 15:02:47.000000000 +0000
+++ src/lread.c
@@ -3429,6 +3429,7 @@ string_to_number (char const *string, in
 	      cp += 3;
 	      value = INFINITY;
 	    }
+#if 0
 	  else if (cp[-1] == '+'
 		   && cp[0] == 'N' && cp[1] == 'a' && cp[2] == 'N')
 	    {
@@ -3437,6 +3438,7 @@ string_to_number (char const *string, in
 	      /* NAN is a "positive" NaN on all known Emacs hosts.  */
 	      value = NAN;
 	    }
+#endif
 	  else
 	    cp = ecp;
 	}
