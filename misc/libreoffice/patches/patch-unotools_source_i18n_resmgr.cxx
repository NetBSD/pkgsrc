$NetBSD: patch-unotools_source_i18n_resmgr.cxx,v 1.1 2023/01/22 17:56:04 ryoon Exp $

Fix build with Boost-1.81.0.
From: https://github.com/LibreOffice/core/commit/23dcd4339428e4080029ec5ae658e75f01e79a62

--- unotools/source/i18n/resmgr.cxx.orig	2022-11-16 17:29:15.000000000 +0000
+++ unotools/source/i18n/resmgr.cxx
@@ -127,8 +127,13 @@ namespace Translate
         if (aFind != aCache.end())
             return aFind->second;
         boost::locale::generator gen;
+#if BOOST_VERSION < 108100
         gen.characters(boost::locale::char_facet);
         gen.categories(boost::locale::message_facet | boost::locale::information_facet);
+#else
+        gen.characters(boost::locale::char_facet_t::char_f);
+        gen.categories(boost::locale::category_t::message | boost::locale::category_t::information);
+#endif
 #if defined(ANDROID)
         OString sPath(OString(lo_get_app_data_dir()) + "/program/resource");
 #else
