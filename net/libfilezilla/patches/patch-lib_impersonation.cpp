$NetBSD: patch-lib_impersonation.cpp,v 1.2 2022/02/07 10:53:52 wiz Exp $

Hide Linux-specific stuff in ifdef __Linux__
https://trac.filezilla-project.org/ticket/12658

--- lib/impersonation.cpp.orig	2021-12-08 15:10:58.000000000 +0000
+++ lib/impersonation.cpp
@@ -7,7 +7,7 @@
 #include <optional>
 #include <tuple>
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 #include <crypt.h>
 #include <shadow.h>
 #endif
@@ -58,7 +58,7 @@ passwd_holder get_passwd(fz::native_stri
 	return ret;
 }
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -150,7 +150,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(fz::native_string const& username, fz::native_string const& password)
 {
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
