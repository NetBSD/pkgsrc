$NetBSD: patch-src_mp4__tag.c,v 1.1 2012/12/03 22:39:05 wiz Exp $

Gentoo patch for mp4v2-2.0 compatibility.
https://bugs.gentoo.org/show_bug.cgi?id=409281

--- src/mp4_tag.c.orig	2011-07-04 00:59:21.000000000 +0000
+++ src/mp4_tag.c
@@ -80,15 +80,9 @@ gboolean Mp4tag_Read_File_Tag (gchar *fi
 {
     FILE   *file;
     MP4FileHandle mp4file = NULL;
-    uint16_t track, track_total;
-    uint16_t disk, disktotal;
-    u_int8_t *coverArt;
-    u_int32_t coverSize;
     Picture *prev_pic = NULL;
-#ifdef NEWMP4
     gint pic_num;
-#endif
-    
+
     if (!filename || !FileTag)
         return FALSE;
 
@@ -102,7 +96,7 @@ gboolean Mp4tag_Read_File_Tag (gchar *fi
     fclose(file); // We close it cause mp4 opens/closes file itself
 
     /* Get data from tag */
-    mp4file = MP4Read(filename, 0);
+    mp4file = MP4Read(filename);
     if (mp4file == MP4_INVALID_FILE_HANDLE)
     {
         gchar *filename_utf8 = filename_to_display(filename);
@@ -111,109 +105,134 @@ gboolean Mp4tag_Read_File_Tag (gchar *fi
         return FALSE;
     }
 
+    const MP4Tags* tags = MP4TagsAlloc();
+    MP4TagsFetch(tags, mp4file);
+
     /* TODO Add error detection */
 
     /*********
      * Title *
      *********/
-    MP4GetMetadataName(mp4file, &FileTag->title);
+    if (tags->name)
+    {
+        FileTag->title = Try_To_Validate_Utf8_String(tags->name);
+    }
 
     /**********
      * Artist *
      **********/
-    MP4GetMetadataArtist(mp4file, &FileTag->artist);
+    if (tags->artist)
+    {
+        FileTag->artist = Try_To_Validate_Utf8_String(tags->artist);
+    }
+
+    /****************
+     * Album Artist *
+     ****************/
+    if (tags->albumArtist)
+    {
+        FileTag->album_artist = Try_To_Validate_Utf8_String(tags->albumArtist);
+    }
 
     /*********
      * Album *
      *********/
-    MP4GetMetadataAlbum(mp4file, &FileTag->album);
+    if (tags->album)
+    {
+        FileTag->album = Try_To_Validate_Utf8_String(tags->album);
+    }
 
     /**********************
      * Disk / Total Disks *
      **********************/
-    if (MP4GetMetadataDisk(mp4file, &disk, &disktotal))
+    if (tags->disk)
     {
-        if (disk != 0 && disktotal != 0)
-            FileTag->disc_number = g_strdup_printf("%d/%d",(gint)disk,(gint)disktotal);
-        else if (disk != 0)
-            FileTag->disc_number = g_strdup_printf("%d",(gint)disk);
-        else if (disktotal != 0)
-            FileTag->disc_number = g_strdup_printf("/%d",(gint)disktotal);
-        //if (disktotal != 0)
-        //    FileTag->disk_number_total = g_strdup_printf("%d",(gint)disktotal);
+        if (tags->disk->index != 0 && tags->disk->total != 0)
+            FileTag->disc_number = g_strdup_printf("%d/%d",(gint)tags->disk->index,(gint)tags->disk->total);
+        else if (tags->disk->index != 0)
+            FileTag->disc_number = g_strdup_printf("%d",(gint)tags->disk->index);
+        else if (tags->disk->total != 0)
+            FileTag->disc_number = g_strdup_printf("/%d",(gint)tags->disk->total);
     }
 
     /********
      * Year *
      ********/
-    MP4GetMetadataYear(mp4file, &FileTag->year);
+    if (tags->releaseDate)
+    {
+        FileTag->year = Try_To_Validate_Utf8_String(tags->releaseDate);
+    }
 
     /*************************
      * Track and Total Track *
      *************************/
-    if (MP4GetMetadataTrack(mp4file, &track, &track_total))
+    if (tags->track)
     {
-        if (track != 0)
-            FileTag->track = g_strdup_printf("%.*d",NUMBER_TRACK_FORMATED_SPIN_BUTTON,(gint)track); // Just to have numbers like this : '01', '05', '12', ...
-        if (track_total != 0)
-            FileTag->track_total = g_strdup_printf("%.*d",NUMBER_TRACK_FORMATED_SPIN_BUTTON,(gint)track_total); // Just to have numbers like this : '01', '05', '12', ...
+        if (tags->track->index != 0)
+            FileTag->track = g_strdup_printf("%.*d",NUMBER_TRACK_FORMATED_SPIN_BUTTON,(gint)tags->track->index); // Just to have numbers like this : '01', '05', '12', ...
+        if (tags->track->total != 0)
+            FileTag->track_total = g_strdup_printf("%.*d",NUMBER_TRACK_FORMATED_SPIN_BUTTON,(gint)tags->track->total); // Just to have numbers like this : '01', '05', '12', ...
     }
 
     /*********
      * Genre *
      *********/
-    MP4GetMetadataGenre(mp4file, &FileTag->genre);
+    if (tags->genre)
+    {
+        FileTag->genre = Try_To_Validate_Utf8_String(tags->genre);
+    }
 
     /***********
      * Comment *
      ***********/
-    MP4GetMetadataComment(mp4file, &FileTag->comment);
+    if (tags->comments)
+    {
+        FileTag->comment = Try_To_Validate_Utf8_String(tags->comments);
+    }
 
     /**********************
      * Composer or Writer *
      **********************/
-    MP4GetMetadataWriter(mp4file, &FileTag->composer);
+    if (tags->composer)
+    {
+        FileTag->composer = Try_To_Validate_Utf8_String(tags->composer);
+    }
 
     /*****************
      * Encoding Tool *
      *****************/
-    MP4GetMetadataTool(mp4file, &FileTag->encoded_by);
-
-    /* Unimplemented
-    Tempo / BPM
-    MP4GetMetadataTempo(file, &string)
-    */
+    if (tags->encodedBy)
+    {
+        FileTag->encoded_by = Try_To_Validate_Utf8_String(tags->encodedBy);
+    }
 
     /***********
      * Picture *
      ***********/
-#ifdef NEWMP4
-    // There version can handle multiple pictures!
-    // Version 1.6 of libmp4v2 introduces an index argument for MP4GetMetadataCoverart
-    for (pic_num = 0; (MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize,pic_num )); pic_num++)
-#else
-    // There version handle only one picture!
-    if ( MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize ) )
-#endif
-    {
-        Picture *pic;
-        
-        pic = Picture_Allocate();
-        if (!prev_pic)
-            FileTag->picture = pic;
-        else
-            prev_pic->next = pic;
-        prev_pic = pic;
-
-        pic->size = coverSize;
-        pic->data = coverArt;
-        pic->type = PICTURE_TYPE_FRONT_COVER;
-        pic->description = NULL;
+    if (tags->artworkCount) {
+        const MP4TagArtwork* art = tags->artwork; /* artwork != NULL when artworkCount > 0 */
+        for (pic_num = 0; pic_num < tags->artworkCount; pic_num++, art++)
+        {
+            Picture *pic;
+
+            pic = Picture_Allocate();
+            if (!prev_pic)
+                FileTag->picture = pic;
+            else
+                prev_pic->next = pic;
+            prev_pic = pic;
+
+            pic->size = art->size;
+            pic->data = g_memdup(art->data, pic->size);
+            pic->type = PICTURE_TYPE_FRONT_COVER;
+            pic->description = NULL;
+        }
     }
 
 
     /* Free allocated data */
-    MP4Close(mp4file);
+    MP4TagsFree(tags);
+    MP4Close(mp4file, 0);
 
     return TRUE;
 }
@@ -235,6 +254,7 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
     FILE     *file;
     MP4FileHandle mp4file = NULL;
     gint error = 0;
+    gint pic_num;
 
     if (!ETFile || !ETFile->FileTag)
         return FALSE;
@@ -252,23 +272,25 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
     fclose(file);
 
     /* Open file for writing */
-    mp4file = MP4Modify(filename,0,0);
+    mp4file = MP4Modify(filename, 0);
     if (mp4file == MP4_INVALID_FILE_HANDLE)
     {
         Log_Print(LOG_ERROR,_("ERROR while opening file: '%s' (%s)."),filename_utf8,_("MP4 format invalid"));
         return FALSE;
     }
 
+    const MP4Tags* tags = MP4TagsAlloc();
+    MP4TagsFetch(tags, mp4file);
+
     /*********
      * Title *
      *********/
     if (FileTag->title && g_utf8_strlen(FileTag->title, -1) > 0)
     {
-        MP4SetMetadataName(mp4file, FileTag->title);
+        MP4TagsSetName(tags, FileTag->title);
     }else
     {
-        //MP4DeleteMetadataName(mp4file); // Not available on mpeg4ip-1.2 (only in 1.3)
-        MP4SetMetadataName(mp4file, "");
+        MP4TagsSetName(tags, "");
     }
 
     /**********
@@ -276,11 +298,21 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      **********/
     if (FileTag->artist && g_utf8_strlen(FileTag->artist, -1) > 0)
     {
-        MP4SetMetadataArtist(mp4file, FileTag->artist);
+        MP4TagsSetArtist(tags, FileTag->artist);
+    }else
+    {
+        MP4TagsSetArtist(tags, "");
+    }
+
+    /****************
+     * Album Artist *
+     ****************/
+    if (FileTag->artist && g_utf8_strlen(FileTag->artist, -1) > 0)
+    {
+        MP4TagsSetAlbumArtist(tags, FileTag->album_artist);
     }else
     {
-        //MP4DeleteMetadataArtist(mp4file);
-        MP4SetMetadataArtist(mp4file, "");
+        MP4TagsSetAlbumArtist(tags, "");
     }
 
     /*********
@@ -288,22 +320,19 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      *********/
     if (FileTag->album && g_utf8_strlen(FileTag->album, -1) > 0)
     {
-        MP4SetMetadataAlbum(mp4file, FileTag->album);
+        MP4TagsSetAlbum(tags, FileTag->album);
     }else
     {
-        //MP4DeleteMetadataAlbum(mp4file);
-        MP4SetMetadataAlbum(mp4file, "");
+        MP4TagsSetAlbum(tags, "");
     }
 
     /**********************
      * Disk / Total Disks *
      **********************/
+    MP4TagDisk td;
     if (FileTag->disc_number && g_utf8_strlen(FileTag->disc_number, -1) > 0)
     //|| FileTag->disc_number_total && g_utf8_strlen(FileTag->disc_number_total, -1) > 0)
     {
-        uint16_t disk      = 0;
-        uint16_t disktotal = 0;
-
         /* At the present time, we manage only disk number like '1' or '1/2', we
          * don't use disk number total... so here we try to decompose */
         if (FileTag->disc_number)
@@ -314,27 +343,24 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
             {
                 // A disc_number_total was entered
                 if ( (tmp+1) && atoi(tmp+1) )
-                    disktotal = atoi(tmp+1);
+                    td.total = atoi(tmp+1);
 
                 // Fill disc_number
                 *tmp = '\0';
-                disk = atoi(dn_tmp);
+                td.index = atoi(dn_tmp);
             }else
             {
-                disk = atoi(FileTag->disc_number);
+                td.index = atoi(FileTag->disc_number);
+                td.total = NULL;
             }
             g_free(dn_tmp);
         }
-        /*if (FileTag->disc_number)
-            disk = atoi(FileTag->disc_number);
-        if (FileTag->disc_number_total)
-            disktotal = atoi(FileTag->disc_number_total);
-        */
-        MP4SetMetadataDisk(mp4file, disk, disktotal);
+        MP4TagsSetDisk(tags, &td);
     }else
     {
-        //MP4DeleteMetadataDisk(mp4file);
-        MP4SetMetadataDisk(mp4file, 0, 0);
+        td.index = NULL;
+        td.total = NULL;
+        MP4TagsSetDisk(tags, &td);
     }
 
     /********
@@ -342,30 +368,29 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      ********/
     if (FileTag->year && g_utf8_strlen(FileTag->year, -1) > 0)
     {
-        MP4SetMetadataYear(mp4file, FileTag->year);
+        MP4TagsSetReleaseDate(tags, FileTag->year);
     }else
     {
-        //MP4DeleteMetadataYear(mp4file);
-        MP4SetMetadataYear(mp4file, "");
+        MP4TagsSetReleaseDate(tags, "");
     }
 
     /*************************
      * Track and Total Track *
      *************************/
+    MP4TagTrack tt;
     if ( (FileTag->track       && g_utf8_strlen(FileTag->track, -1) > 0)
     ||   (FileTag->track_total && g_utf8_strlen(FileTag->track_total, -1) > 0) )
     {
-        uint16_t track       = 0;
-        uint16_t track_total = 0;
         if (FileTag->track)
-            track = atoi(FileTag->track);
+            tt.index = atoi(FileTag->track);
         if (FileTag->track_total)
-            track_total = atoi(FileTag->track_total);
-        MP4SetMetadataTrack(mp4file, track, track_total);
+            tt.total = atoi(FileTag->track_total);
+        MP4TagsSetTrack(tags, &tt);
     }else
     {
-        //MP4DeleteMetadataTrack(mp4file);
-        MP4SetMetadataTrack(mp4file, 0, 0);
+        tt.index = NULL;
+        tt.total = NULL;
+        MP4TagsSetTrack(tags, &tt);
     }
 
     /*********
@@ -373,11 +398,10 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      *********/
     if (FileTag->genre && g_utf8_strlen(FileTag->genre, -1) > 0 )
     {
-        MP4SetMetadataGenre(mp4file, FileTag->genre);
+        MP4TagsSetGenre(tags, FileTag->genre);
     }else
     {
-        //MP4DeleteMetadataGenre(mp4file);
-        MP4SetMetadataGenre(mp4file, "");
+        MP4TagsSetGenre(tags, "");
     }
 
     /***********
@@ -385,11 +409,10 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      ***********/
     if (FileTag->comment && g_utf8_strlen(FileTag->comment, -1) > 0)
     {
-        MP4SetMetadataComment(mp4file, FileTag->comment);
+        MP4TagsSetComments(tags, FileTag->comment);
     }else
     {
-        //MP4DeleteMetadataComment(mp4file);
-        MP4SetMetadataComment(mp4file, "");
+        MP4TagsSetComments(tags, "");
     }
 
     /**********************
@@ -397,11 +420,10 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      **********************/
     if (FileTag->composer && g_utf8_strlen(FileTag->composer, -1) > 0)
     {
-        MP4SetMetadataWriter(mp4file, FileTag->composer);
+        MP4TagsSetComposer(tags, FileTag->composer);
     }else
     {
-        //MP4DeleteMetadataWriter(mp4file);
-        MP4SetMetadataWriter(mp4file, "");
+        MP4TagsSetComposer(tags, "");
     }
 
     /*****************
@@ -409,33 +431,39 @@ gboolean Mp4tag_Write_File_Tag (ET_File 
      *****************/
     if (FileTag->encoded_by && g_utf8_strlen(FileTag->encoded_by, -1) > 0)
     {
-        MP4SetMetadataTool(mp4file, FileTag->encoded_by);
+        MP4TagsSetEncodedBy(tags, FileTag->encoded_by);
     }else
     {
-        //MP4DeleteMetadataTool(mp4file);
-        MP4SetMetadataTool(mp4file, "");
+        MP4TagsSetEncodedBy(tags, "");
     }
 
     /***********
      * Picture *
      ***********/
+    Picture *pic = FileTag->picture;
+    const gint artworkCount = tags->artworkCount;
+
+    for (pic_num = 0; pic_num < artworkCount; pic_num++)
     {
-        // Can handle only one picture...
-        Picture *pic;
+        MP4TagsRemoveArtwork(tags, 0);
+    }
 
-        //MP4DeleteMetadataCoverArt(mp4file);
-        MP4SetMetadataCoverArt(mp4file, NULL, 0);
-        for( pic = FileTag->picture; pic; pic = pic->next )
+    while (pic)
+    {
+        if (pic->data)
         {
-            if( pic->type == PICTURE_TYPE_FRONT_COVER )
-            {
-                MP4SetMetadataCoverArt(mp4file, pic->data, pic->size);
-            }
+            MP4TagArtwork art;
+            art.data = pic->data;
+            art.size = pic->size;
+            art.type = MP4_ART_UNDEFINED; // delegate typing to libmp4v2
+            MP4TagsAddArtwork(tags, &art);
         }
+        pic = pic->next;
     }
 
-
-    MP4Close(mp4file);
+    MP4TagsStore(tags, mp4file);
+    MP4TagsFree(tags);
+    MP4Close(mp4file, 0);
 
     if (error) return FALSE;
     else       return TRUE;
