$NetBSD: patch-gnulib_lib_mbiter.h,v 1.1 2011/02/06 13:04:04 obache Exp $

* http://savannah.gnu.org/bugs/?24687

--- gnulib/lib/mbiter.h.orig	2008-05-12 12:38:21.000000000 +0000
+++ gnulib/lib/mbiter.h
@@ -117,8 +117,10 @@ mbiter_multi_next (struct mbiter_multi *
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
@@ -129,6 +131,7 @@ mbiter_multi_next (struct mbiter_multi *
       iter->cur.wc = *iter->cur.ptr;
       iter->cur.wc_valid = true;
     }
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   else
     {
       assert (mbsinit (&iter->state));
@@ -169,6 +172,7 @@ mbiter_multi_next (struct mbiter_multi *
 	    iter->in_shift = false;
 	}
     }
+#endif
   iter->next_done = true;
 }
 
