$NetBSD: patch-src_megacmdcommonutils.cpp,v 1.1 2025/02/15 07:40:14 wiz Exp $

* BSDs use the functions of linux

--- src/megacmdcommonutils.cpp.orig	2025-02-07 09:43:13.320748794 +0100
+++ src/megacmdcommonutils.cpp
@@ -1128,7 +1128,8 @@ bool isValidEmail(string email)
                     || (email.find("@") > email.find_last_of(".")));
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 std::string getCurrentExecPath()
 {
     std::string path = ".";
