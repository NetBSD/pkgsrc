$NetBSD: patch-gnulib_lib_mbiter.h,v 1.3 2023/11/07 22:05:01 wiz Exp $

* http://savannah.gnu.org/bugs/?24687

--- gnulib/lib/mbiter.h.orig	2023-08-13 18:30:28.000000000 +0000
+++ gnulib/lib/mbiter.h
@@ -129,8 +129,10 @@ mbiter_multi_next (struct mbiter_multi *
   if (iter->next_done)
     return;
   #if !GNULIB_MBRTOC32_REGULAR
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   if (iter->in_shift)
     goto with_shift;
+#endif
   #endif
   /* Handle most ASCII characters quickly, without calling mbrtowc().  */
   if (is_basic (*iter->cur.ptr))
@@ -145,6 +147,7 @@ mbiter_multi_next (struct mbiter_multi *
       iter->cur.wc = *iter->cur.ptr;
       iter->cur.wc_valid = true;
     }
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   else
     {
       assert (mbsinit (&iter->state));
@@ -202,6 +205,7 @@ mbiter_multi_next (struct mbiter_multi *
           #endif
         }
     }
+#endif
   iter->next_done = true;
 }
 
