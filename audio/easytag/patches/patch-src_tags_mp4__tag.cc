$NetBSD: patch-src_tags_mp4__tag.cc,v 1.1 2024/02/01 09:45:59 wiz Exp $

Fix build with taglib2
https://gitlab.archlinux.org/archlinux/packaging/packages/easytag/-/blob/main/taglib-2.patch?ref_type=heads
https://gitlab.gnome.org/GNOME/easytag/-/issues/92

--- src/tags/mp4_tag.cc.orig	2016-06-24 14:57:32.000000000 +0000
+++ src/tags/mp4_tag.cc
@@ -222,7 +222,7 @@ mp4tag_read_file_tag (GFile *file,
         FileTag->encoded_by = g_strdup (encodedbys.front ().toCString (true));
     }
 
-    const TagLib::MP4::ItemListMap &extra_items = tag->itemListMap ();
+    const TagLib::MP4::ItemMap &extra_items = tag->itemMap ();
 
     /* Album Artist */
 #if (TAGLIB_MAJOR_VERSION == 1) && (TAGLIB_MINOR_VERSION < 10)
@@ -437,25 +437,12 @@ mp4tag_write_file_tag (const ET_File *ET
         fields.insert ("ENCODEDBY", string);
     }
 
-    TagLib::MP4::ItemListMap &extra_items = tag->itemListMap ();
-
     /* Album artist. */
     if (!et_str_empty (FileTag->album_artist))
     {
         TagLib::String string (FileTag->album_artist, TagLib::String::UTF8);
-#if (TAGLIB_MAJOR_VERSION == 1) && (TAGLIB_MINOR_VERSION < 10)
-        /* No "ALBUMARTIST" support in TagLib until 1.10; use atom directly. */
-        extra_items.insert ("aART", TagLib::MP4::Item (string));
-#else
         fields.insert ("ALBUMARTIST", string);
-#endif
     }
-#if (TAGLIB_MAJOR_VERSION == 1) && (TAGLIB_MINOR_VERSION < 10)
-    else
-    {
-        extra_items.erase ("aART");
-    }
-#endif
 
     /***********
      * Picture *
@@ -491,12 +478,12 @@ mp4tag_write_file_tag (const ET_File *ET
         TagLib::MP4::CoverArt art (f, TagLib::ByteVector((char *)data,
                                                          data_size));
 
-        extra_items.insert ("covr",
+        tag->setItem("covr",
                             TagLib::MP4::Item (TagLib::MP4::CoverArtList ().append (art)));
     }
     else
     {
-        extra_items.erase ("covr");
+        tag->removeItem("covr");
     }
 
     tag->setProperties (fields);
