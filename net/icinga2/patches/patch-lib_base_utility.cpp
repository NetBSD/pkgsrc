$NetBSD: patch-lib_base_utility.cpp,v 1.1 2021/01/15 00:37:17 wiz Exp $

Fix 'fs::copy_option' has not been declared with boost 1.74.0

Upstream Issue #8185, Pull Request #8184, commit c30bae2994f1e5f33f6da51eb96d423e9bf0f75c

--- lib/base/utility.cpp.orig
+++ lib/base/utility.cpp
@@ -725,7 +725,11 @@ void Utility::CopyFile(const String& source, const String& target)
 {
 	namespace fs = boost::filesystem;
 
+#if BOOST_VERSION >= 107400
+	fs::copy_file(fs::path(source.Begin(), source.End()), fs::path(target.Begin(), target.End()), fs::copy_options::overwrite_existing);
+#else /* BOOST_VERSION */
 	fs::copy_file(fs::path(source.Begin(), source.End()), fs::path(target.Begin(), target.End()), fs::copy_option::overwrite_if_exists);
+#endif /* BOOST_VERSION */
 }
 
 /*
