$NetBSD: patch-lib_tgchat_ext_td_tdutils_td_utils_port_detail_KQueue.cpp,v 1.1 2026/04/06 13:46:38 nia Exp $

On recent NetBSD releases this workaround now causes a compilation
error, so limit it to older releases.

--- lib/tgchat/ext/td/tdutils/td/utils/port/detail/KQueue.cpp.orig	2026-04-06 11:28:02.175309265 +0000
+++ lib/tgchat/ext/td/tdutils/td/utils/port/detail/KQueue.cpp
@@ -16,6 +16,7 @@ char disable_linker_warning_about_empty_file_kqueue_cp
 #include <cerrno>
 #include <utility>
 
+#include <sys/param.h>
 #include <sys/time.h>
 #include <unistd.h>
 
@@ -84,7 +85,7 @@ void KQueue::add_change(std::uintptr_t ident, int16 fi
   if (changes_n_ == static_cast<int>(events_.size())) {
     flush_changes();
   }
-#if TD_NETBSD
+#if TD_NETBSD && (defined(__NetBSD__) && __NetBSD_Version__ < 999001500)
   auto set_udata = reinterpret_cast<std::intptr_t>(udata);
 #else
   auto set_udata = udata;
