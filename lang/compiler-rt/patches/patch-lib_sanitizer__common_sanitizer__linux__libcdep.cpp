$NetBSD: patch-lib_sanitizer__common_sanitizer__linux__libcdep.cpp,v 1.7 2025/02/03 19:55:34 wiz Exp $

Fix build on NetBSD-current, where some symbols moved to a new header.
https://github.com/llvm/llvm-project/issues/125566

--- lib/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2024-06-15 17:21:32.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -29,7 +29,13 @@
 #  include "sanitizer_solaris.h"
 
 #  if SANITIZER_NETBSD
-#    define _RTLD_SOURCE  // for __lwp_gettcb_fast() / __lwp_getprivate_fast()
+#    // for __lwp_gettcb_fast() / __lwp_getprivate_fast()
+#    include <sys/param.h>
+#    if defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 1099001200)
+#      include <machine/lwp_private.h>
+#    else
+#      define _RTLD_SOURCE
+#    endif
 #  endif
 
 #  include <dlfcn.h>  // for dlsym()
