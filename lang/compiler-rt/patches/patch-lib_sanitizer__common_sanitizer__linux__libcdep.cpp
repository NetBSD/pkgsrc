$NetBSD: patch-lib_sanitizer__common_sanitizer__linux__libcdep.cpp,v 1.8 2025/02/14 13:45:09 wiz Exp $

Fix build on NetBSD-current, where some symbols moved to a new header.
https://github.com/llvm/llvm-project/issues/125566

--- lib/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2024-06-15 17:21:32.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -29,7 +29,14 @@
 #  include "sanitizer_solaris.h"
 
 #  if SANITIZER_NETBSD
-#    define _RTLD_SOURCE  // for __lwp_gettcb_fast() / __lwp_getprivate_fast()
+#    // for __lwp_gettcb_fast() / __lwp_getprivate_fast()
+#    define _RTLD_SOURCE
+#    include <machine/mcontext.h>
+#    undef _RTLD_SOURCE
+#    include <sys/param.h>
+#    if __NetBSD_Version__ >= 1099001200
+#      include <machine/lwp_private.h>
+#    endif
 #  endif
 
 #  include <dlfcn.h>  // for dlsym()
