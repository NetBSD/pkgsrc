$NetBSD: patch-lib_mp4_util.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/util.c.orig	2017-09-25 14:55:01.074628967 +0000
+++ lib/mp4/util.c
@@ -131,14 +131,14 @@ int quicktime_test_position(quicktime_t 
 	return 0;
 }
 
-int quicktime_read_pascal(quicktime_t *file, char *data)
+void quicktime_read_pascal(quicktime_t *file, char *data)
 {
 	char len = quicktime_read_char(file);
 	quicktime_read_data(file, data, len);
 	data[len] = 0;
 }
 
-int quicktime_write_pascal(quicktime_t *file, char *data)
+void quicktime_write_pascal(quicktime_t *file, char *data)
 {
 	char len = strlen(data);
 	quicktime_write_data(file, &len, 1);
@@ -326,7 +326,7 @@ int quicktime_write_char(quicktime_t *fi
 	return quicktime_write_data(file, &x, 1);
 }
 
-int quicktime_read_char32(quicktime_t *file, char *string)
+void quicktime_read_char32(quicktime_t *file, char *string)
 {
 	quicktime_read_data(file, string, 4);
 /*	fread(string, 4, 1, file->stream); */
@@ -344,7 +344,7 @@ int quicktime_set_position(quicktime_t *
 /*	fseek(file->stream, position, SEEK_SET);  */
 }
 
-int quicktime_copy_char32(char *output, char *input)
+void quicktime_copy_char32(char *output, char *input)
 {
 	*output++ = *input++;
 	*output++ = *input++;
@@ -352,8 +352,7 @@ int quicktime_copy_char32(char *output, 
 	*output = *input;
 }
 
-
-int quicktime_print_chars(char *desc, char *input, int len)
+void quicktime_print_chars(char *desc, char *input, int len)
 {
 	int i;
 	printf("%s", desc);
