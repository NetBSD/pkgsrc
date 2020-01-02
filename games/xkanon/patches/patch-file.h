$NetBSD: patch-file.h,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Avoid unalignd word accesses even on little endian (for arm and mips).

--- file.h.orig	2008-01-06 06:20:00.000000000 +0000
+++ file.h
@@ -38,27 +38,19 @@
 #include<stdlib.h>
 #include<string.h>
 
-#if defined(__sparc) || defined(sparc)
-#  if !defined(WORDS_BIGENDIAN)
-#    define WORDS_BIGENDIAN 1
-#  endif
-#endif
+#define INT_SIZE sizeof(int)
 
-#ifdef WORDS_BIGENDIAN
-
-#define INT_SIZE 4
-
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
@@ -72,7 +64,7 @@ static int write_little_endian_int(char*
 	return c;
 }
 
-static int write_little_endian_short(char* buf, int number) {
+static inline int write_little_endian_short(char* buf, int number) {
 	int c = read_little_endian_short(buf);
 	unsigned char *p = (unsigned char *) buf;
 	unsigned int unum = (unsigned int) number;
@@ -82,28 +74,6 @@ static int write_little_endian_short(cha
 	return c;
 }
 
-#else // defined(WORDS_BIGENDIAN)
-
-// assume little endian...
-#define INT_SIZE 4
-
-inline int read_little_endian_int(const char* buf) {
-	return *(int*)buf;
-}
-
-inline int read_little_endian_short(const char* buf) {
-	return *(short*)buf;
-}
-
-inline int write_little_endian_int(char* buf, int number) {
-	int c = *(int*)buf; *(int*)buf = number; return c;
-}
-
-inline int write_little_endian_short(char* buf, int number) {
-	int c = *(short*)buf; *(short*)buf = number; return c;
-}
-#endif // WORDS_BIGENDIAN
-
 /*********************************************
 **  FILESEARCH:
 **	書庫ファイル／ディレクトリを含め、
