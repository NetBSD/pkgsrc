$NetBSD: patch-src_dvd_reader.c,v 1.1 2011/08/09 20:53:15 adam Exp $

Provide DVDFileStat functions; patch from http://dvdbackup.sourceforge.net/

--- src/dvd_reader.c.orig	2008-09-06 21:55:51.000000000 +0000
+++ src/dvd_reader.c
@@ -889,6 +889,187 @@ void DVDCloseFile( dvd_file_t *dvd_file 
     }
 }
 
+static int DVDFileStatVOBUDF(dvd_reader_t *dvd, int title, 
+                             int menu, dvd_stat_t *statbuf)
+{
+  char filename[ MAX_UDF_FILE_NAME_LEN ];
+  uint32_t size;
+  off_t tot_size;
+  off_t parts_size[9];
+  int nr_parts = 0;
+  int n;
+ 
+  if( title == 0 ) {
+    sprintf( filename, "/VIDEO_TS/VIDEO_TS.VOB" );
+  } else {
+    sprintf( filename, "/VIDEO_TS/VTS_%02d_%d.VOB", title, menu ? 0 : 1 );
+  }
+  if(!UDFFindFile( dvd, filename, &size )) {
+    return -1;
+  }
+  tot_size = size;
+  nr_parts = 1;
+  parts_size[0] = size;
+
+  if( !menu ) {
+    int cur;
+
+    for( cur = 2; cur < 10; cur++ ) {
+      sprintf( filename, "/VIDEO_TS/VTS_%02d_%d.VOB", title, cur );
+      if( !UDFFindFile( dvd, filename, &size ) ) {
+        break;
+      }
+      parts_size[nr_parts] = size;
+      tot_size += size;
+      nr_parts++;
+    }
+  }
+  
+  statbuf->size = tot_size;
+  statbuf->nr_parts = nr_parts;
+  for(n = 0; n < nr_parts; n++) {
+    statbuf->parts_size[n] = parts_size[n];
+  }
+  return 0;
+}
+
+
+static int DVDFileStatVOBPath( dvd_reader_t *dvd, int title,
+                                       int menu, dvd_stat_t *statbuf )
+{
+  char filename[ MAX_UDF_FILE_NAME_LEN ];
+  char full_path[ PATH_MAX + 1 ];
+  struct stat fileinfo;
+  off_t tot_size;
+  off_t parts_size[9];
+  int nr_parts = 0;
+  int n;
+
+ 
+    
+  if( title == 0 ) {
+    sprintf( filename, "VIDEO_TS.VOB" );
+  } else {
+    sprintf( filename, "VTS_%02d_%d.VOB", title, menu ? 0 : 1 );
+  }
+  if( !findDVDFile( dvd, filename, full_path ) ) {
+    return -1;
+  }
+  
+  if( stat( full_path, &fileinfo ) < 0 ) {
+    fprintf( stderr, "libdvdread: Can't stat() %s.\n", filename );
+    return -1;
+  }
+  
+
+  tot_size = fileinfo.st_size;
+  nr_parts = 1;
+  parts_size[0] = fileinfo.st_size;
+
+  if( !menu ) {
+    int cur;
+    
+    for( cur = 2; cur < 10; cur++ ) {
+
+      sprintf( filename, "VTS_%02d_%d.VOB", title, cur );
+      if( !findDVDFile( dvd, filename, full_path ) ) {
+        break;
+      }
+
+      if( stat( full_path, &fileinfo ) < 0 ) {
+        fprintf( stderr, "libdvdread: Can't stat() %s.\n", filename );
+        break;
+      }
+      
+      parts_size[nr_parts] = fileinfo.st_size;
+      tot_size += parts_size[nr_parts];
+      nr_parts++;
+    }
+  }
+
+  statbuf->size = tot_size;
+  statbuf->nr_parts = nr_parts;
+  for(n = 0; n < nr_parts; n++) {
+    statbuf->parts_size[n] = parts_size[n];
+  }
+  return 0;
+}
+
+
+int DVDFileStat(dvd_reader_t *dvd, int titlenum, 
+                dvd_read_domain_t domain, dvd_stat_t *statbuf)
+{
+  char filename[ MAX_UDF_FILE_NAME_LEN ];
+  char full_path[ PATH_MAX + 1 ];
+  struct stat fileinfo;
+  uint32_t size;
+
+  /* Check arguments. */
+  if( dvd == NULL || titlenum < 0 ) {
+    errno = EINVAL;
+    return -1;
+  }
+
+  switch( domain ) {
+  case DVD_READ_INFO_FILE:
+    if( titlenum == 0 ) {
+      sprintf( filename, "/VIDEO_TS/VIDEO_TS.IFO" );
+    } else {
+      sprintf( filename, "/VIDEO_TS/VTS_%02i_0.IFO", titlenum );
+    }
+    break;
+  case DVD_READ_INFO_BACKUP_FILE:
+    if( titlenum == 0 ) {
+      sprintf( filename, "/VIDEO_TS/VIDEO_TS.BUP" );
+    } else {
+      sprintf( filename, "/VIDEO_TS/VTS_%02i_0.BUP", titlenum );
+    }
+    break;
+  case DVD_READ_MENU_VOBS:
+    if( dvd->isImageFile ) {
+      return DVDFileStatVOBUDF( dvd, titlenum, 1, statbuf );
+    } else {
+      return DVDFileStatVOBPath( dvd, titlenum, 1, statbuf );
+    }
+    break;
+  case DVD_READ_TITLE_VOBS:
+    if( titlenum == 0 ) {
+      return -1;
+    }
+    if( dvd->isImageFile ) {
+      return DVDFileStatVOBUDF( dvd, titlenum, 0, statbuf );
+    } else {
+      return DVDFileStatVOBPath( dvd, titlenum, 0, statbuf );
+    }
+    break;
+  default:
+    fprintf( stderr, "libdvdread: Invalid domain for file stat.\n" );
+    errno = EINVAL;
+    return -1;
+  }
+  
+  if( dvd->isImageFile ) {
+    if( UDFFindFile( dvd, filename, &size ) ) {
+      statbuf->size = size;
+      statbuf->nr_parts = 1;
+      statbuf->parts_size[0] = size;
+      return 0;
+    }
+  } else {
+    if( findDVDFile( dvd, filename, full_path ) )  {
+      if( stat( full_path, &fileinfo ) < 0 ) {
+        fprintf( stderr, "libdvdread: Can't stat() %s.\n", filename );
+      } else {
+        statbuf->size = fileinfo.st_size;
+        statbuf->nr_parts = 1;
+        statbuf->parts_size[0] = statbuf->size;
+        return 0;
+      }
+    }
+  }
+  return -1;
+}
+
 /* Internal, but used from dvd_udf.c */
 int UDFReadBlocksRaw( dvd_reader_t *device, uint32_t lb_number,
 			 size_t block_count, unsigned char *data,
