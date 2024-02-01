$NetBSD: patch-src_tags_gio__wrapper.cc,v 1.1 2024/02/01 09:45:59 wiz Exp $

Fix build with taglib2
https://gitlab.archlinux.org/archlinux/packaging/packages/easytag/-/blob/main/taglib-2.patch?ref_type=heads
https://gitlab.gnome.org/GNOME/easytag/-/issues/92

--- src/tags/gio_wrapper.cc.orig	2016-06-24 14:57:32.000000000 +0000
+++ src/tags/gio_wrapper.cc
@@ -47,11 +47,11 @@ GIO_InputStream::name () const
 }
 
 TagLib::ByteVector
-GIO_InputStream::readBlock (TagLib::ulong len)
+GIO_InputStream::readBlock (ulong len)
 {
     if (error)
     {
-        return TagLib::ByteVector::null;
+        return TagLib::ByteVector();
     }
 
     TagLib::ByteVector rv (len, 0);
@@ -70,14 +70,14 @@ GIO_InputStream::writeBlock (TagLib::Byt
 
 void
 GIO_InputStream::insert (TagLib::ByteVector const &data,
-                         TagLib::ulong start,
-                         TagLib::ulong replace)
+                         TagLib::offset_t start,
+                         size_t replace)
 {
     g_warning ("%s", "Trying to write to read-only file!");
 }
 
 void
-GIO_InputStream::removeBlock (TagLib::ulong start, TagLib::ulong len)
+GIO_InputStream::removeBlock (TagLib::offset_t start, size_t len)
 {
     g_warning ("%s", "Trying to write to read-only file!");
 }
@@ -200,11 +200,11 @@ GIO_IOStream::name () const
 }
 
 TagLib::ByteVector
-GIO_IOStream::readBlock (TagLib::ulong len)
+GIO_IOStream::readBlock (ulong len)
 {
     if (error)
     {
-        return TagLib::ByteVector::null;
+        return TagLib::ByteVector();
     }
 
     gsize bytes = 0;
@@ -239,8 +239,8 @@ GIO_IOStream::writeBlock (TagLib::ByteVe
 
 void
 GIO_IOStream::insert (TagLib::ByteVector const &data,
-                      TagLib::ulong start,
-                      TagLib::ulong replace)
+                      TagLib::offset_t start,
+                      size_t replace)
 {
     if (error)
     {
@@ -351,9 +351,9 @@ GIO_IOStream::insert (TagLib::ByteVector
 }
 
 void
-GIO_IOStream::removeBlock (TagLib::ulong start, TagLib::ulong len)
+GIO_IOStream::removeBlock (TagLib::offset_t start, size_t len)
 {
-    if (start + len >= (TagLib::ulong)length ())
+    if (start + len >= (ulong)length ())
     {
         truncate (start);
         return;
