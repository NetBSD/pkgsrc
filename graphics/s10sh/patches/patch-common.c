$NetBSD: patch-common.c,v 1.1 2015/02/23 18:24:00 joerg Exp $

--- common.c.orig	2015-02-23 13:32:08.000000000 +0000
+++ common.c
@@ -57,7 +57,7 @@ void dump_hex(const char *msg, const uns
     fprintf(stderr,"%s: (%d bytes)\n", msg, len);
     while (len > 0)
     {
-        sprintf(line, "%08x: ", buf - start);
+        sprintf(line, "%08zx: ", (size_t)(buf - start));
         out = line + 10;
 
         for (i = 0, pc = buf, nlocal = len; i < 16; i++, pc++)
@@ -423,8 +423,8 @@ int camera_get_image(char *pathname, cha
 		timestamp = time(NULL) - timestamp;
 		if (!timestamp)
 			timestamp = 1;
-		printf("\nDownloaded in %ld seconds, %ld bytes/s\n",
-			timestamp, len/timestamp);
+		printf("\nDownloaded in %lld seconds, %lld bytes/s\n",
+			(long long)timestamp, (long long)(len/timestamp));
 
 		imagedate = get_date_for_image (orig_pathname);
 		
@@ -530,9 +530,9 @@ int camera_get_thumb(char *pathname, cha
 		timestamp = time(NULL) - timestamp;
 		if (!timestamp)
 			timestamp = 1;
-		printf("Downloaded in %ld seconds,"
-			" %ld bytes/s\n",
-			timestamp, len/timestamp);
+		printf("Downloaded in %lld seconds,"
+			" %lld bytes/s\n",
+			(long long)timestamp, (long long)(len/timestamp));
 		free(image);
 	}
 	return 0;
