$NetBSD: patch-src_dvd_reader.h,v 1.1 2011/08/09 20:53:15 adam Exp $

Provide DVDFileStat functions; patch from http://dvdbackup.sourceforge.net/

--- src/dvd_reader.h.orig	2008-09-06 21:55:51.000000000 +0000
+++ src/dvd_reader.h
@@ -115,6 +115,42 @@ typedef enum {
 } dvd_read_domain_t;
 
 /**
+ *
+ */
+typedef struct {
+  off_t size;          /**< Total size of file in bytes */
+  int nr_parts;        /**< Number of file parts */
+  off_t parts_size[9]; /**< Size of each part in bytes */
+} dvd_stat_t;
+
+/**
+ * Stats a file on the DVD given the title number and domain.
+ * The information about the file is stored in a dvd_stat_t
+ * which contains information about the size of the file and
+ * the number of parts in case of a multipart file and the respective
+ * sizes of the parts.
+ * A multipart file is for instance VTS_02_1.VOB, VTS_02_2.VOB, VTS_02_3.VOB
+ * The size of VTS_02_1.VOB will be stored in stat->parts_size[0],
+ * VTS_02_2.VOB in stat->parts_size[1], ...
+ * The total size (sum of all parts) is stored in stat->size and
+ * stat->nr_parts will hold the number of parts.
+ * Only DVD_READ_TITLE_VOBS (VTS_??_[1-9].VOB) can be multipart files.
+ * 
+ * This function is only of use if you want to get the size of each file
+ * in the filesystem. These sizes are not needed to use any other
+ * functions in libdvdread. 
+ *
+ * @param dvd  A dvd read handle.
+ * @param titlenum Which Video Title Set should be used, VIDEO_TS is 0.
+ * @param domain Which domain. 
+ * @param stat Pointer to where the result is stored.
+ * @return If successful 0, otherwise -1.
+ *
+ * int DVDFileStat(dvd, titlenum, domain, stat);
+ */
+int DVDFileStat(dvd_reader_t *, int, dvd_read_domain_t, dvd_stat_t *);
+  
+/**
  * Opens a file on the DVD given the title number and domain.
  *
  * If the title number is 0, the video manager information is opened
