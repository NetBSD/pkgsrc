$NetBSD: patch-gnulib_lib_mbuiter.h,v 1.3 2023/11/07 22:05:01 wiz Exp $

* http://savannah.gnu.org/bugs/?24687

--- gnulib/lib/mbuiter.h.orig	2023-08-13 18:30:28.000000000 +0000
+++ gnulib/lib/mbuiter.h
@@ -138,8 +138,10 @@ mbuiter_multi_next (struct mbuiter_multi
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
@@ -154,6 +156,7 @@ mbuiter_multi_next (struct mbuiter_multi
       iter->cur.wc = *iter->cur.ptr;
       iter->cur.wc_valid = true;
     }
+#if defined(HAVE_MBSINIT) && defined(HAVE_MBRTOWC)
   else
     {
       assert (mbsinit (&iter->state));
@@ -208,6 +211,7 @@ mbuiter_multi_next (struct mbuiter_multi
           #endif
         }
     }
+#endif
   iter->next_done = true;
 }
 
