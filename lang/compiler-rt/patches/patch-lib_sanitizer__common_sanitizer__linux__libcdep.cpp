$NetBSD: patch-lib_sanitizer__common_sanitizer__linux__libcdep.cpp,v 1.4 2022/11/14 18:44:06 adam Exp $

Fix build on NetBSD.

--- lib/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2022-11-10 13:10:42.578954666 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -568,6 +568,7 @@ static void GetTls(uptr *addr, uptr *siz
       *addr = (uptr)tcb->tcb_dtv[1];
     }
   }
+#else
 #error "Unknown OS"
 #endif
 }
