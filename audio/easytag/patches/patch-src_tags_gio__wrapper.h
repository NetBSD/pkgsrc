$NetBSD: patch-src_tags_gio__wrapper.h,v 1.1 2024/02/01 09:45:59 wiz Exp $

Fix build with taglib2
https://gitlab.archlinux.org/archlinux/packaging/packages/easytag/-/blob/main/taglib-2.patch?ref_type=heads
https://gitlab.gnome.org/GNOME/easytag/-/issues/92

--- src/tags/gio_wrapper.h.orig	2016-06-24 14:57:32.000000000 +0000
+++ src/tags/gio_wrapper.h
@@ -33,10 +33,10 @@ public:
     GIO_InputStream (GFile *file_);
     virtual ~GIO_InputStream ();
     virtual TagLib::FileName name () const;
-    virtual TagLib::ByteVector readBlock (TagLib::ulong length);
+    virtual TagLib::ByteVector readBlock (ulong length);
     virtual void writeBlock (TagLib::ByteVector const &data);
-    virtual void insert (TagLib::ByteVector const &data, TagLib::ulong start = 0, TagLib::ulong replace = 0);
-    virtual void removeBlock (TagLib::ulong start = 0, TagLib::ulong length = 0);
+    virtual void insert (TagLib::ByteVector const &data, TagLib::offset_t start = 0, size_t replace = 0);
+    virtual void removeBlock (TagLib::offset_t start = 0, size_t length = 0);
     virtual bool readOnly () const;
     virtual bool isOpen () const;
     virtual void seek (long int offset, TagLib::IOStream::Position p = TagLib::IOStream::Beginning);
@@ -61,10 +61,10 @@ public:
     GIO_IOStream (GFile *file_);
     virtual ~GIO_IOStream ();
     virtual TagLib::FileName name () const;
-    virtual TagLib::ByteVector readBlock (TagLib::ulong length);
+    virtual TagLib::ByteVector readBlock (ulong length);
     virtual void writeBlock (TagLib::ByteVector const &data);
-    virtual void insert (TagLib::ByteVector const &data, TagLib::ulong start = 0, TagLib::ulong replace = 0);
-    virtual void removeBlock (TagLib::ulong start = 0, TagLib::ulong len = 0);
+    virtual void insert (TagLib::ByteVector const &data, TagLib::offset_t start = 0, size_t replace = 0);
+    virtual void removeBlock (TagLib::offset_t start = 0, size_t len = 0);
     virtual bool readOnly () const;
     virtual bool isOpen () const;
     virtual void seek (long int offset, TagLib::IOStream::Position p = TagLib::IOStream::Beginning);
