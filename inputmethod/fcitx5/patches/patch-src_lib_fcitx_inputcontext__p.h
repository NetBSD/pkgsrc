$NetBSD: patch-src_lib_fcitx_inputcontext__p.h,v 1.1 2022/12/18 11:41:39 nros Exp $

Make sure uuiod.h from libuuid is included, when using <uuid.h>
the risk is that uuid.h from /usr/include gets included on BSD
systems and it does not have uuid_generate causeing build failure.

--- src/lib/fcitx/inputcontext_p.h.orig	2022-12-18 11:28:32.792366572 +0000
+++ src/lib/fcitx/inputcontext_p.h
@@ -15,7 +15,7 @@
 #include <fcitx/inputpanel.h>
 #include <fcitx/instance.h>
 #include <fcitx/statusarea.h>
-#include <uuid.h>
+#include <uuid/uuid.h>
 
 namespace fcitx {
 
