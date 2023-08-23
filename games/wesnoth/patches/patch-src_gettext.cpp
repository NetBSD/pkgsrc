$NetBSD: patch-src_gettext.cpp,v 1.1 2023/08/23 08:01:06 adam Exp $

Fix for Boost 1.83.0.
https://github.com/wesnoth/wesnoth/issues/7849

--- src/gettext.cpp.orig	2023-08-23 05:46:06.000000000 +0000
+++ src/gettext.cpp
@@ -169,7 +169,11 @@ namespace
 			return msg;
 		}
 
+#if BOOST_VERSION < 108300
 		const char* get(int domain_id, const char* ctx, const char* sid, int n) const override
+#else
+ 		const char* get(int domain_id, const char* ctx, const char* sid, bl::count_type n) const override
+#endif
 		{
 			auto& base = get_base();
 			const char* msg = base.get(domain_id, ctx, sid, n);
