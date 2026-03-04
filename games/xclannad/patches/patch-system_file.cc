$NetBSD: patch-system_file.cc,v 1.3 2026/03/04 12:38:01 tsutsui Exp $

- avoid unaligned copy for RISC cpus (XXX: handle NetBSD only)
- fix a missing return value warning
- appease -Wwrite-strings warnings

--- system/file.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ system/file.cc
@@ -93,7 +93,7 @@ FILESEARCH::ARCTYPE FILESEARCH::default_
 	ATYPE_DIR, ATYPE_DIR, ATYPE_DIR, ATYPE_DIR,
 	ATYPE_DIR, ATYPE_DIR
 };
-char* FILESEARCH::default_dirnames[TYPEMAX] = {
+const char* FILESEARCH::default_dirnames[TYPEMAX] = {
 	0, 0, "", "pdt", 
 	"seen.txt", "allanm.anl", "allard.ard", "allcur.cur", 
 	0, 0, "koe", "bgm", "mov", "gan"};
@@ -107,14 +107,14 @@ char* FILESEARCH::default_dirnames[TYPEM
 **	Find したものをReadすると内容が得られる。
 */
 
-ARCFILE::ARCFILE(char* aname) {
+ARCFILE::ARCFILE(const char* aname) {
 	struct stat sb;
 	/* 変数初期化 */
 	arcname = 0;
 	list_point = 0;
 	filenames_orig = 0;
 	next = 0;
-	if (aname[0] == '\0') {arcname=new char[1]; arcname[0]='\0';return;} // NULFILE
+	if (aname == NULL || aname[0] == '\0') {arcname=new char[1]; arcname[0]='\0';return;} // NULFILE
 	/* ディレクトリか否かのチェック */
 	if (stat(aname,&sb) == -1) { /* error */
 		perror("stat");
@@ -614,8 +614,9 @@ void FILESEARCH::SetFileInformation(FILE
 	/* 適当に初期化 */
 	if (filenames[type] != 0 &&
 		filenames[type] != default_dirnames[type]) delete[] filenames[type];
-	filenames[type] = new char[strlen(filename)+1];
-	strcpy(filenames[type], filename);
+	char *p = new char[strlen(filename)+1];
+	strcpy(p, filename);
+	filenames[type] = p;
 	is_archived[type] = is_arc;
 	searcher[type] = MakeARCFILE(is_arc, filename);
 	if (searcher[type] && next_arc)
@@ -645,7 +646,7 @@ void FILESEARCH::AppendFileInformation(F
 	return;
 }
 
-ARCFILE* FILESEARCH::MakeARCFILE(ARCTYPE tp, char* filename) {
+ARCFILE* FILESEARCH::MakeARCFILE(ARCTYPE tp, const char* filename) {
 	ARCFILE* arc = 0;
 	char* file;
 	if (filename == 0) goto err;
@@ -1067,6 +1068,7 @@ bool G00CONV::Read(char* image) {
 	if (type == 0) return Read_Type0(image);
 	else if (type == 1) return Read_Type1(image);
 	else if (type == 2) return Read_Type2(image);
+	return false;
 }
 
 /* 一般的な LZ 圧縮の展開ルーチン */
@@ -1161,14 +1163,8 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
-#ifdef WORDS_BIGENDIAN
-		ldest[3] = lsrc[0];
-		ldest[2] = lsrc[1];
-		ldest[1] = lsrc[2];
-		ldest[0] = 0;
-#else
-		*(int*)ldest = read_little_endian_int(lsrc); ldest[3]=0;
-#endif
+		memcpy(ldest, lsrc, 3);
+		ldest[3] = 0;
 		lsrc += 3; ldest += 4;
 	}
 	static int IsRev(void) { return 0; }
@@ -1246,13 +1242,7 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
-#ifdef WORDS_BIGENDIAN
-		ldest[0] = lsrc[0];
-		ldest[1] = lsrc[1];
-		ldest[2] = lsrc[2];
-#else /* LITTLE ENDIAN / intel architecture */
-		*(int*)ldest = *(int*)lsrc;
-#endif
+		memcpy(ldest, lsrc, 3);
 		lsrc += 3; ldest += 3;
 	}
 	static int IsRev(void) { return 1; }
@@ -1279,7 +1269,7 @@ bool PDTCONV::Read(char* image) {
 	int i; int len = width*height;
 	src = buf; dest = image;
 	for (i=0; i<len; i++) {
-		*(int*)dest |= int(*(unsigned char*)src) << 24;
+		write_little_endian_int(dest, (int)((unsigned char)src[0]) << 24 | read_little_endian_int(dest)); 
 		src++;
 		dest += 4;
 	}
@@ -1328,9 +1318,12 @@ bool PDTCONV::Read_PDT11(char* image) {
 		cur += 4;
 	}
 	src = image + width*height;
-	int* desti = (int*)(image + width*height*4);
-	while(desti != (int*)image)
-		*--desti = color_table[*(unsigned char*)--src];
+	char *desti = (image + width*height*4);
+	while(desti != image) {
+		desti -= sizeof(int);
+		--src;
+		(void)write_little_endian_int(desti, color_table[(int)(unsigned char)src[0]]);
+	}
 	return true;
 }
 
@@ -1475,8 +1468,8 @@ bool G00CONV::Read_Type1(char* image) {
 	srcend = uncompress_data + uncompress_size;
 	dest = image; destend = image + width*height*4;
 	while(dest < destend && src < srcend) {
-		*(int*)dest = colortable[*(unsigned char*)src];
-		dest += 4; src ++;
+		write_little_endian_int(dest, colortable[(int)(unsigned char)src[0]]);
+		dest += sizeof(int); src ++;
 	}
 	delete[] uncompress_data;
 	return true;
@@ -1541,16 +1534,17 @@ bool G00CONV::Read_Type2(char* image) {
 
 void G00CONV::Copy_32bpp(char* image, int x, int y, const char* src, int bpl, int h) {
 	int i;
-	int* dest = (int*)(image + x*4 + y*4*width);
+	char* dest = (image + x*4 + y*4*width);
 	int w = bpl / 4;
 	for (i=0; i<h; i++) {
 		const char* s = src;
-		int* d = dest;
+		char* d = dest;
 		int j; for (j=0; j<w; j++) {
-			*d++ = read_little_endian_int(s);
+			write_little_endian_int(d, read_little_endian_int(s));
+			d += sizeof(int);
 			s += 4;
 		}
-		src += bpl; dest += width;
+		src += bpl; dest += width * sizeof(int);
 	}
 }
 
@@ -1560,10 +1554,10 @@ void GRPCONV::CopyRGBA_rev(char* image, 
 	int len = width * height;
 	int i;
 	unsigned char* s = (unsigned char*)buf;
-	int* d = (int*)image;
+	char* d = image;
 	for(i=0; i<len; i++) {
-		*d = (int(s[2])) | (int(s[1])<<8) | (int(s[0])<<16) | (int(s[3])<<24) | mask;
-		d++; s += 4;
+		write_little_endian_int(d, (int(s[2])) | (int(s[1])<<8) | (int(s[0])<<16) | (int(s[3])<<24) | mask);
+		d += 4; s += 4;
 	}
 	return;
 }
@@ -1576,9 +1570,10 @@ void GRPCONV::CopyRGBA(char* image, cons
 	/* 色変換を行う */
 	int len = width * height;
 	int i;
-	int* outbuf = (int*)image;
+	char* outbuf = image;
 	for(i=0; i<len; i++) {
-		*outbuf++ =  read_little_endian_int(buf);
+		write_little_endian_int(outbuf, read_little_endian_int(buf));
+		outbuf += 4;
 		buf += 4;
 	}
 	return;
@@ -1588,10 +1583,10 @@ void GRPCONV::CopyRGB(char* image, const
 	int len = width * height;
 	int i;
 	unsigned char* s = (unsigned char*)buf;
-	int* d = (int*)image;
+	char* d = image;
 	for(i=0; i<len; i++) {
-		*d = (int(s[0])) | (int(s[1])<<8) | (int(s[2])<<16) | 0xff000000;
-		d++; s+=3;
+		write_little_endian_int(d, (int(s[0])) | (int(s[1])<<8) | (int(s[2])<<16) | 0xff000000);
+		d += sizeof(int); s+=3;
 	}
 	return;
 }
