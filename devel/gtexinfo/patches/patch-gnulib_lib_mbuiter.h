$NetBSD: patch-gnulib_lib_mbuiter.h,v 1.1 2011/02/06 13:04:04 obache Exp $

* http://savannah.gnu.org/bugs/?24687

--- gnulib/lib/mbuiter.h.orig	2007-12-25 23:57:18.000000000 +0000
+++ gnulib/lib/mbuiter.h
@@ -125,8 +125,10 @@ mbuiter_multi_next (struct mbuiter_multi
 {
   if (iter->next_done)
     return;
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   if (iter->in_shift)
     goto with_shift;
+#endif
   /* Handle most ASCII characters quickly, without calling mbrtowc().  */
   if (is_basic (*iter->cur.ptr))
     {
@@ -137,6 +139,7 @@ mbuiter_multi_next (struct mbuiter_multi
       iter->cur.wc = *iter->cur.ptr;
       iter->cur.wc_valid = true;
     }
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   else
     {
       assert (mbsinit (&iter->state));
@@ -178,6 +181,7 @@ mbuiter_multi_next (struct mbuiter_multi
 	    iter->in_shift = false;
 	}
     }
+#endif
   iter->next_done = true;
 }
 
