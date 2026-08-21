$NetBSD: patch-lib_impersonation.cpp,v 1.5 2026/08/21 12:29:04 wiz Exp $

Hide Linux-specific stuff in ifdef __Linux__
https://trac.filezilla-project.org/ticket/12658

--- lib/impersonation.cpp.orig	2026-08-18 13:40:55.000000000 +0000
+++ lib/impersonation.cpp
@@ -81,7 +81,7 @@ impersonation_token::impersonation_token(fz::user cons
 
 #include "libfilezilla/buffer.hpp"
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 #include <crypt.h>
 #include <shadow.h>
 #endif
@@ -177,7 +177,7 @@ std::optional<gid_t> get_group(native_string const& gn
 	return {};
 }
 
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -265,7 +265,7 @@ bool check_auth(native_string const& username, native_
 
 bool check_auth(native_string const& username, native_string const& password)
 {
-#if FZ_UNIX
+#if FZ_UNIX && defined(__Linux__)
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
