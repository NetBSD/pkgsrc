$NetBSD: patch-gnulib_lib_mbiter.h,v 1.2 2013/07/04 16:19:16 wiz Exp $

* http://savannah.gnu.org/bugs/?24687

--- gnulib/lib/mbiter.h.orig	2013-02-19 22:25:29.000000000 +0000
+++ gnulib/lib/mbiter.h
@@ -122,8 +122,10 @@ mbiter_multi_next (struct mbiter_multi *
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
@@ -134,6 +136,7 @@ mbiter_multi_next (struct mbiter_multi *
       iter->cur.wc = *iter->cur.ptr;
       iter->cur.wc_valid = true;
     }
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   else
     {
       assert (mbsinit (&iter->state));
@@ -174,6 +177,7 @@ mbiter_multi_next (struct mbiter_multi *
             iter->in_shift = false;
         }
     }
+#endif
   iter->next_done = true;
 }
 
