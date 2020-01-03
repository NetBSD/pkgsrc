$NetBSD: patch-window_button.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- avoid unaligned copy for RISC cpus

--- window/button.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ window/button.cc
@@ -471,6 +471,7 @@ void ButtonColor::SetBrightness(int c1, 
 #include"rect.h"
 #include<stdlib.h>
 #include<string.h>
+#include"system/file.h"
 
 static void draw_button(char* rdata, int width, int height, char* bdata, int bwidth, int bheight, const ButtonColor& color) {
 	const int* rs = color.rs;
@@ -514,8 +515,8 @@ static void draw_button(char* rdata, int
 		ScaleData* d = data + y*width;
 		char* rd = rdata + y*width*4;
 		for (x=0; x<width; x++) {
-			if (d->c == 0) *(int*)rd = 0;
-			else *(int*)rd = (int(d->b / d->c)&0xff)| ((int(d->g / d->c)&0xff)<<8)| ((int(d->r / d->c)&0xff)<<16)| ((int(d->a / d->c)&0xff)<<24);
+			if (d->c == 0) memset(rd, 0, sizeof(int));
+			else write_little_endian_int(rd, (int(d->b / d->c)&0xff)| ((int(d->g / d->c)&0xff)<<8)| ((int(d->r / d->c)&0xff)<<16)| ((int(d->a / d->c)&0xff)<<24));
 			rd += 4;
 			d++;
 		}
@@ -556,7 +557,7 @@ static void drawbox(char* buf, const Rec
 	for (i=0; i<h; i++) {
 		char* c = buf;
 		for (j=0; j<w; j++) {
-			*(int*)c = col;
+			write_little_endian_int(c, col);
 			c += 4;
 		}
 		buf += width*4;
@@ -684,7 +685,7 @@ int main(void) {
 	if(f==0)return 0;
 	create_png(f,w,h*3,c);
 	for (i=0;i<w*h;i++) {
-		printf("%08x,",*(int*)(c+i*4));
+		printf("%08x,",read_little_endian_int(c+i*4));
 		if ( (i&7)==7) printf("\n");
 	}
 	return 0;
