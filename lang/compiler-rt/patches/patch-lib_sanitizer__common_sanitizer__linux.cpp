$NetBSD: patch-lib_sanitizer__common_sanitizer__linux.cpp,v 1.3 2026/04/20 10:02:51 tnn Exp $

Fix build for platforms other than Linux and FreeBSD. NetBSD/evbarm-aarch64:
sanitizer_linux.cpp:2057:8: error: 'Aarch64GetESR' was not declared in this scope
 2057 |   if (!Aarch64GetESR(ucontext, &esr))

--- lib/sanitizer_common/sanitizer_linux.cpp.orig	2024-07-03 11:57:05.400879120 +0000
+++ lib/sanitizer_common/sanitizer_linux.cpp
@@ -1886,7 +1886,7 @@ static bool Aarch64GetESR(ucontext_t *uc
   }
   return false;
 }
-#  elif SANITIZER_FREEBSD && defined(__aarch64__)
+#  elif defined(__aarch64__)
 // FreeBSD doesn't provide ESR in the ucontext.
 static bool Aarch64GetESR(ucontext_t *ucontext, u64 *esr) { return false; }
 #  endif
