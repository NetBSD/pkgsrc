$NetBSD: patch-src_mp3fs.cc,v 1.2 2021/12/01 14:41:15 pho Exp $

Hunk #0:
    <fuse_common.h> is not meant to be directly #include'd by user
    code. It's only an implementation detail, and librefuse doesn't
    provide one.

Hunk #1:
    Work around an issue in librefuse <fuse_opt.h>. It has been
    incompatible with C++11 compilers. Fixed in HEAD:
    * http://mail-index.netbsd.org/source-changes/2021/12/01/msg134169.html
    * http://mail-index.netbsd.org/source-changes/2021/12/01/msg134170.html

--- src/mp3fs.cc.orig	2021-01-31 04:07:18.000000000 +0000
+++ src/mp3fs.cc
@@ -26,7 +26,6 @@
 #define FUSE_USE_VERSION 26
 
 #include <fuse.h>
-#include <fuse_common.h>
 #include <fuse_opt.h>
 #ifdef __APPLE__
 #include <fuse_darwin.h>
@@ -63,6 +62,8 @@ enum { KEY_HELP, KEY_VERSION, KEY_KEEP_O
 #define FUSE_OPT_KEY(templ, key) \
     { templ, (unsigned int)(-1), key }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wnarrowing"
 struct fuse_opt mp3fs_opts[] = {
     MP3FS_OPT("-b %d", bitrate, 0),
     MP3FS_OPT("bitrate=%d", bitrate, 0),
@@ -98,6 +99,7 @@ struct fuse_opt mp3fs_opts[] = {
     FUSE_OPT_KEY("-d", KEY_KEEP_OPT),
     FUSE_OPT_KEY("debug", KEY_KEEP_OPT),
     FUSE_OPT_END};
+#pragma GCC diagnostic pop
 
 void usage(const std::string& name) {
     std::cout << "Usage: " << name << " [OPTION]... IN_DIR OUT_DIR"
