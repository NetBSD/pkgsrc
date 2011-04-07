$NetBSD: patch-pp.c,v 1.1 2011/04/07 04:03:58 taca Exp $

* Fix for http://secunia.com/advisories/43921/ from perl's git repository
  (539689e74a).

--- pp.c.orig	2010-09-06 23:30:32.000000000 +0000
+++ pp.c
@@ -3949,6 +3949,8 @@ PP(pp_ucfirst)
 	    SvCUR_set(dest, need - 1);
 	}
     }
+    if (dest != source && SvTAINTED(source))
+	SvTAINT(dest);
     SvSETMAGIC(dest);
     RETURN;
 }
@@ -4222,6 +4224,8 @@ PP(pp_uc)
 	    SvCUR_set(dest, d - (U8*)SvPVX_const(dest));
 	}
     } /* End of isn't utf8 */
+    if (dest != source && SvTAINTED(source))
+	SvTAINT(dest);
     SvSETMAGIC(dest);
     RETURN;
 }
@@ -4433,6 +4437,8 @@ PP(pp_lc)
 	    SvCUR_set(dest, d - (U8*)SvPVX_const(dest));
 	}
     }
+    if (dest != source && SvTAINTED(source))
+	SvTAINT(dest);
     SvSETMAGIC(dest);
     RETURN;
 }
