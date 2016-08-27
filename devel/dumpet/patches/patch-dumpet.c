$NetBSD: patch-dumpet.c,v 1.1 2016/08/27 11:53:39 nonaka Exp $

--- dumpet.c.orig	2010-08-25 16:54:11.000000000 +0000
+++ dumpet.c	2016-08-26 00:17:46.000000000 +0000
@@ -285,7 +285,8 @@ static int dumpBootImage(struct context 
 		image = fopen(filename, "w+");
 		if (!image) {
 			int errnum;
-			fprintf(stderr, "Could not open \"%s\": %m\n", filename);
+			fprintf(stderr, "Could not open \"%s\": %s\n",
+			    filename, strerror(errno));
 			errnum = errno;
 			free(filename);
 			return -errnum;
@@ -781,14 +782,16 @@ int main(int argc, char *argv[])
 
 	context.iso = fopen(context.filename, "r");
 	if (!context.iso) {
-		fprintf(stderr, "Could not open \"%s\": %m\n", context.filename);
+		fprintf(stderr, "Could not open \"%s\": %s\n",
+		    context.filename, strerror(errno));
 		exit(2);
 	}
 
 	if (context.dumpXml) {
 		xml = xmlBufferCreate();
 		if (!xml) {
-			fprintf(stderr, "Error creating XML buffer: %m\n");
+			fprintf(stderr, "Error creating XML buffer: %s\n",
+			    strerror(errno));
 			exit(3);
 		}
 		context.writer = xmlNewTextWriterMemory(xml, 0);
