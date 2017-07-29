$NetBSD: patch-boost_locale_localization__backend.hpp,v 1.1 2017/07/29 10:00:03 wiz Exp $

Avoid deprecated auto_ptr.
https://github.com/boostorg/locale/pull/19

--- boost/locale/localization_backend.hpp.orig	2017-04-17 02:22:21.000000000 +0000
+++ boost/locale/localization_backend.hpp
@@ -104,14 +104,14 @@ namespace boost {
             ///
             /// Create new localization backend according to current settings.
             ///
-            std::auto_ptr<localization_backend> get() const;
+            std::unique_ptr<localization_backend> get() const;
 
             ///
             /// Add new backend to the manager, each backend should be uniquely defined by its name.
             ///
             /// This library provides: "icu", "posix", "winapi" and "std" backends.
             ///
-            void add_backend(std::string const &name,std::auto_ptr<localization_backend> backend);
+            void add_backend(std::string const &name,std::unique_ptr<localization_backend> backend);
 
             ///
             /// Clear backend
@@ -143,7 +143,7 @@ namespace boost {
             static localization_backend_manager global();
         private:
             class impl;
-            std::auto_ptr<impl> pimpl_;
+            std::unique_ptr<impl> pimpl_;
         };
 
     } // locale
