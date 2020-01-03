$NetBSD: patch-system_file.h,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- make stream little endian read/write functions inline

--- system/file.h.orig	2008-01-06 05:17:13.000000000 +0000
+++ system/file.h
@@ -51,17 +51,17 @@
 
 #define INT_SIZE 4
 
-static int read_little_endian_int(const char* buf) {
+static inline int read_little_endian_int(const char* buf) {
 	const unsigned char *p = (const unsigned char *) buf;
 	return (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
 }
 
-static int read_little_endian_short(const char* buf) {
+static inline int read_little_endian_short(const char* buf) {
 	const unsigned char *p = (const unsigned char *) buf;
 	return (p[1] << 8) | p[0];
 }
 
-static int write_little_endian_int(char* buf, int number) {
+static inline int write_little_endian_int(char* buf, int number) {
 	int c = read_little_endian_int(buf);
 	unsigned char *p = (unsigned char *) buf;
 	unsigned int unum = (unsigned int) number;
@@ -75,7 +75,7 @@ static int write_little_endian_int(char*
 	return c;
 }
 
-static int write_little_endian_short(char* buf, int number) {
+static inline int write_little_endian_short(char* buf, int number) {
 	int c = read_little_endian_short(buf);
 	unsigned char *p = (unsigned char *) buf;
 	unsigned int unum = (unsigned int) number;
