$NetBSD: patch-src_dfxml_src_dfxml__writer.cpp,v 1.1 2017/07/14 12:58:25 joerg Exp $

--- src/dfxml/src/dfxml_writer.cpp.orig	2017-07-12 22:50:57.618132822 +0000
+++ src/dfxml/src/dfxml_writer.cpp
@@ -710,7 +710,7 @@ void dfxml_writer::add_DFXML_build_envir
 #ifdef HAVE_EXIV2
     xmlout("library", "", std::string("name=\"exiv2\" version=\"") + Exiv2::version() + "\"",false);
 #endif
-#if defined(HAVE_LIBTRE) && defined(HAVE_TRE_VERSION)
+#if defined(HAVE_LIBTRE) && defined(HAVE_TRE_VERSION) && defined(HAVE_TRE_TRE_H)
     xmlout("library", "", std::string("name=\"tre\" version=\"") + tre_version() + "\"",false);
 #endif
 #ifdef HAVE_HASHID
