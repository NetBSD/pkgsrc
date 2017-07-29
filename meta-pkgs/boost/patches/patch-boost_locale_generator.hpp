$NetBSD: patch-boost_locale_generator.hpp,v 1.1 2017/07/29 10:00:03 wiz Exp $

Avoid deprecated auto_ptr.
https://github.com/boostorg/locale/pull/19

--- boost/locale/generator.hpp.orig	2017-04-17 02:22:21.000000000 +0000
+++ boost/locale/generator.hpp
@@ -220,7 +220,7 @@ namespace boost {
             void operator=(generator const &);
 
             struct data;
-            std::auto_ptr<data> d;
+            std::unique_ptr<data> d;
         };
 
     }
