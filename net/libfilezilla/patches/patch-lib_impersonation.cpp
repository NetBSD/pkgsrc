$NetBSD: patch-lib_impersonation.cpp,v 1.3 2022/05/04 05:46:46 wiz Exp $

Hide Linux-specific stuff in ifdef __Linux__
https://trac.filezilla-project.org/ticket/12658

--- lib/impersonation.cpp.orig	2022-04-01 12:35:07.000000000 +0000
+++ lib/impersonation.cpp
@@ -7,7 +7,7 @@
 #include <optional>
 #include <tuple>
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 #include <crypt.h>
 #include <shadow.h>
 #endif
@@ -79,7 +79,7 @@ std::optional<gid_t> get_group(fz::nativ
 	return {};
 }
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -171,7 +171,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(fz::native_string const& username, fz::native_string const& password)
 {
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
