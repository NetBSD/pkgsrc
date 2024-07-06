$NetBSD: patch-lib_sanitizer__common_sanitizer__linux.cpp,v 1.1 2024/07/06 15:45:06 adam Exp $

Fix build for platforms other than Linux and FreeBSD.

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
