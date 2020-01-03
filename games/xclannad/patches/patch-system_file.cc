$NetBSD: patch-system_file.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- avoid unaligned copy for RISC cpus (XXX: handle NetBSD only)

--- system/file.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ system/file.cc
@@ -1161,14 +1161,8 @@ public:
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
@@ -1246,13 +1240,7 @@ public:
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
@@ -1279,7 +1267,7 @@ bool PDTCONV::Read(char* image) {
 	int i; int len = width*height;
 	src = buf; dest = image;
 	for (i=0; i<len; i++) {
-		*(int*)dest |= int(*(unsigned char*)src) << 24;
+		write_little_endian_int(dest, (int)((unsigned char)src[0]) << 24 | read_little_endian_int(dest)); 
 		src++;
 		dest += 4;
 	}
@@ -1328,9 +1316,12 @@ bool PDTCONV::Read_PDT11(char* image) {
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
 
@@ -1475,8 +1466,8 @@ bool G00CONV::Read_Type1(char* image) {
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
@@ -1541,16 +1532,17 @@ bool G00CONV::Read_Type2(char* image) {
 
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
 
@@ -1560,10 +1552,10 @@ void GRPCONV::CopyRGBA_rev(char* image, 
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
@@ -1576,9 +1568,10 @@ void GRPCONV::CopyRGBA(char* image, cons
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
@@ -1588,10 +1581,10 @@ void GRPCONV::CopyRGB(char* image, const
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
