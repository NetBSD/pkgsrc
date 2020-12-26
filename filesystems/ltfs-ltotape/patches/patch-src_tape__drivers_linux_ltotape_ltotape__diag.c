$NetBSD: patch-src_tape__drivers_linux_ltotape_ltotape__diag.c,v 1.1 2020/12/26 05:23:12 mef Exp $

ICU_6.8 adaptation

--- src/tape_drivers/linux/ltotape/ltotape_diag.c.orig	2019-03-15 04:24:46.000000000 +0000
+++ src/tape_drivers/linux/ltotape/ltotape_diag.c
@@ -137,7 +137,7 @@ char* ltotape_set_snapshotdir (char* new
 /****************************************************************************
  * Request, retrieve and store a drive log snapshot
  * @param device a pointer to the ltotape backend tape device
- * @param minidump TRUE, to generate mini dump or FALSE, to generate full dump
+ * @param minidump true, to generate mini dump or false, to generate full dump
  * @return 0 on success or negative value on error
  */
 int ltotape_log_snapshot (void *device, int minidump)
@@ -380,7 +380,7 @@ static int ltotape_read_drivedump (void 
 	int buf_id;
 	unsigned char cap_buf[DUMP_HEADER_SIZE];
 	unsigned char *dump_buf;
-	bool updated_header = FALSE;
+	bool updated_header = false;
 	time_t               now;
 	int                  j;
 
@@ -454,7 +454,7 @@ static int ltotape_read_drivedump (void 
 		}
 
 		/* Update the header */
-		if (updated_header == FALSE) {
+		if (updated_header == false) {
 			dump_buf [ LTOTAPE_TIMESTAMP_TYPE_OFFSET   ] = 0x00;
 			dump_buf [ LTOTAPE_TIMESTAMP_TYPE_OFFSET+1 ] = 0x02; /* type2=UTC */
 
@@ -471,7 +471,7 @@ static int ltotape_read_drivedump (void 
 			for (j = 0; j < LTOTAPE_LIBSN_LENGTH; j++) {
 				dump_buf [ LTOTAPE_LIBSN_OFFSET+j ] = (unsigned char) *(lsn+j);
 			}
-			updated_header = TRUE;
+			updated_header = true;
 		}
 
 		/* write buffer data into dump file */
@@ -523,14 +523,14 @@ static long long ltotape_get_buffer_size
   size = -1;
   buf_offset = 32;
   bytes_processed = 0;
-  not_found = TRUE;
+  not_found = true;
 
   data_length = (((int)buffer[30]) << 8) + (int)buffer[31];
 
   while (not_found && (bytes_processed < data_length)) {
 
     if (buff_id == buffer[buf_offset]) {
-      not_found = FALSE;
+      not_found = false;
       size = (((long long)buffer[buf_offset + 4]) << 24) + 
              (((long long)buffer[buf_offset + 5]) << 16) + 
              (((long long)buffer[buf_offset + 6]) <<  8) + 
@@ -561,7 +561,7 @@ static int ltotape_read_mini_drivedump (
 	int buf_id;
 	unsigned char cap_buf[MINI_DUMP_HEADER_SIZE];
 	unsigned char *dump_buf;
-	bool updated_header = FALSE;
+	bool updated_header = false;
 	time_t               now;
 	int                  j;
 
@@ -640,7 +640,7 @@ static int ltotape_read_mini_drivedump (
 		}
 
 		/* Update the header */
-		if (updated_header == FALSE) {
+		if (updated_header == false) {
 			dump_buf [ LTOTAPE_TIMESTAMP_TYPE_OFFSET   ] = 0x00;
 			dump_buf [ LTOTAPE_TIMESTAMP_TYPE_OFFSET+1 ] = 0x02; /* type2=UTC */
 
@@ -657,7 +657,7 @@ static int ltotape_read_mini_drivedump (
 			for (j = 0; j < LTOTAPE_LIBSN_LENGTH; j++) {
 				dump_buf [ LTOTAPE_LIBSN_OFFSET+j ] = (unsigned char) *(lsn+j);
 			}
-			updated_header = TRUE;
+			updated_header = true;
 		}
 
 		/* write buffer data into dump file */
