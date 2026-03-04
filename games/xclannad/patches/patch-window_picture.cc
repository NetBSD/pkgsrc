$NetBSD: patch-window_picture.cc,v 1.2 2026/03/04 14:15:03 tsutsui Exp $

- avoid unaligned copy for RISC cpus
- try to use SDL_WM_SetCaption() with utf-8 conversion

--- window/picture.cc.orig	2008-01-06 05:17:14.000000000 +0000
+++ window/picture.cc
@@ -370,7 +370,7 @@ err_ret:
 			char* s = (char*)((SDL_Surface*)surface_own)->pixels + ((SDL_Surface*)surface_own)->pitch*i;
 			int bpp = ((SDL_Surface*)surface_own)->format->BytesPerPixel;
 			for (j=0; j<w; j++) {
-				if ( ((*(int*)s) & 0xffffff) == 0) *a = 0;
+				if ( (read_little_endian_int(s) & 0xffffff) == 0) *a = 0;
 				else if (*a == 0) *a = 0xff;
 				s += bpp; a++;
 			}
@@ -730,10 +730,10 @@ inline Surface* FileToSurface::LoadSurfa
 		MaskType is_mask = conv->IsMask() ? ALPHA_MASK : NO_MASK;
 		if (is_mask == ALPHA_MASK) { // alpha がすべて 0xff ならマスク無しとする
 			int len = conv->Width()*conv->Height();
-			unsigned int* d = (unsigned int*)mem;
+			char* d = mem;
 			int i; for (i=0; i<len; i++) {
-				if ( (*d&0xff000000) != 0xff000000) break;
-				d++;
+				if ( (read_little_endian_int(d)&0xff000000) != 0xff000000) break;
+				d += 4;
 			}
 			if (i == len) {
 				is_mask = NO_MASK;
@@ -1009,8 +1009,16 @@ bool PicRoot::with_mask(Surface* s) {
 #endif /* USE_X11 */
 void PicRoot::SetWindowCaption(const char* caption) {
 #if USE_X11
-//	SDL_WM_SetCaption(caption, 0);
-	// SDLの関数では2バイト文字をサポートしてくれないので、同等の内容に修正
+	// SDL 1.2 でも utf-8 をまず仮定する
+	// SetWindowCaption() の呼び出し側では kconv() で EUC 変換されている
+	char *caption_utf8 = SDL_iconv_string("UTF-8", "euc-jp",
+	    caption, strlen(caption) + 1);
+	if (caption_utf8 != NULL) {
+		SDL_WM_SetCaption(caption_utf8, 0);
+		SDL_free(caption_utf8);
+		return;
+	}
+	// 変換に失敗した場合は同等の内容にフォールバック
 	SDL_SysWMinfo info;
 	memset(&info,0,sizeof(info));
 	SDL_VERSION(&(info.version));
