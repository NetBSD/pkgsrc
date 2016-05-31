$NetBSD: patch-src_ssl_rec__wri.cpp,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/rec_wri.cpp.orig	2016-05-25 20:42:21.289208827 +0000
+++ src/ssl/rec_wri.cpp
@@ -16,7 +16,7 @@ namespace Botan {
 /**
 * Record_Writer Constructor
 */
-Record_Writer::Record_Writer(std::tr1::function<void (const byte[], size_t)> out) :
+Record_Writer::Record_Writer(function<void (const byte[], size_t)> out) :
    output_fn(out),
    buffer(DEFAULT_BUFFERSIZE)
    {
