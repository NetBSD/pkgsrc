$NetBSD: patch-system_file.h,v 1.2 2026/03/04 10:27:20 tsutsui Exp $

- make stream little endian read/write functions inline
- appease -Wwrite-strings warning

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
@@ -132,10 +132,10 @@ private:
 	ARCFILE* searcher[TYPEMAX];
 	/* ファイルの存在位置の information */
 	ARCTYPE is_archived[TYPEMAX];
-	char* filenames[TYPEMAX];
+	const char* filenames[TYPEMAX];
 	/* デフォルトの information */
 	static ARCTYPE default_is_archived[TYPEMAX];
-	static char* default_dirnames[TYPEMAX];
+	static const char* default_dirnames[TYPEMAX];
 public:
 	FILESEARCH(void);
 	~FILESEARCH();
@@ -147,7 +147,7 @@ public:
 	/* 複数のファイルを一つの型に関連づける */
 	void AppendFileInformation(FILETYPE type, ARCTYPE is_arc,
 		char* filename);
-	ARCFILE* MakeARCFILE(ARCTYPE tp, char* filename);
+	ARCFILE* MakeARCFILE(ARCTYPE tp, const char* filename);
 	/* fname で指定された名前のファイルを検索 */
 	class ARCINFO* Find(FILETYPE type, const char* fname, const char* ext=0);
 	/* ある種類のファイルをすべてリストアップ
