$NetBSD: patch-ui_curses.c,v 1.2 2019/04/25 23:54:46 kamil Exp $

* For NetBSD curses
* Switch unportable iconv(3) UCS-2 <-> wchar_t conversions
  to a portable algorithm with an intermediate step with
  multibyte sequences

--- ui/curses.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ ui/curses.c
@@ -46,6 +46,11 @@
 #define FONT_HEIGHT 16
 #define FONT_WIDTH 8
 
+#if defined(__NetBSD__)
+#define chars vals
+#define attr attributes
+#endif
+
 enum maybe_keycode {
     CURSES_KEYCODE,
     CURSES_CHAR,
@@ -400,6 +405,8 @@ static void curses_atexit(void)
     endwin();
 }
 
+
+#if 0
 /* Setup wchar glyph for one UCS-2 char */
 static void convert_ucs(int glyph, uint16_t ch, iconv_t conv)
 {
@@ -653,6 +660,253 @@ static void font_setup(void)
     iconv_close(wchar_to_ucs_conv);
     iconv_close(font_conv);
 }
+#else
+static void convert_ucs(int glyph, uint16_t ch, iconv_t conv)
+{
+    char nch[MB_CUR_MAX];
+    wchar_t wch;
+    char *pch, *pwch, *pnch;
+    size_t sch, swch, snch;
+
+    pch = (char *) &ch;
+    pwch = (char *) &wch;
+    pnch = (char *) nch;
+    sch = sizeof(ch);
+    swch = sizeof(wch);
+    snch = sizeof(nch);
+
+    if (iconv(conv, &pch, &sch, &pnch, &snch) == (size_t) -1) {
+        fprintf(stderr, "Could not convert 0x%04x from UCS-2 to a multibyte character: %s\n",
+                        ch, strerror(errno));
+        return;
+    }
+
+    if (mbtowc(&wch, nch, sizeof(nch) - snch) == -1) {
+        fprintf(stderr, "Could not convert 0x%04x from a multibyte character to wchar_t: %s\n",
+                        ch, strerror(errno));
+        return;
+    }
+    vga_to_curses[glyph].chars[0] = wch;
+}
+
+static void convert_font(unsigned char ch)
+{
+    wchar_t wch;
+
+    mbtowc(&wch, (char *)&ch, 1);
+    vga_to_curses[ch].chars[0] = wch;
+}
+
+/* Convert one wchar to UCS-2 */
+static uint16_t get_ucs(wchar_t wch, iconv_t conv)
+{
+    char nch[MB_CUR_MAX];
+    char *pnch;
+    size_t snch;
+
+    uint16_t ch;
+    char *pch;
+    size_t sch;
+
+    pnch = (char *) nch;
+    pch = (char *) &ch;
+    sch = sizeof(ch);
+
+    if ((snch = wctomb(nch, wch)) == -1) {
+         fprintf(stderr, "Could not convert 0x%04x from wchar_t to a multibyte character: %s\n",
+                        ch, strerror(errno));
+         return 0xFFFD;
+    }
+
+    if (iconv(conv, &sch, &snch, &pch, &sch) == (size_t) -1) {
+        fprintf(stderr, "Could not convert 0x%04x from a multibyte character to UCS-2 : %s\n",
+                        ch, strerror(errno));
+        return 0xFFFD;
+    }
+
+    return ch;
+}
+
+static void font_setup(void)
+{
+    iconv_t ucs2_to_nativecharset;
+    iconv_t nativecharset_to_ucs2;
+    int i;
+
+    /*
+     * Control characters are normally non-printable, but VGA does have
+     * well-known glyphs for them.
+     */
+    static uint16_t control_characters[0x20] = {
+      0x0020,
+      0x263a,
+      0x263b,
+      0x2665,
+      0x2666,
+      0x2663,
+      0x2660,
+      0x2022,
+      0x25d8,
+      0x25cb,
+      0x25d9,
+      0x2642,
+      0x2640,
+      0x266a,
+      0x266b,
+      0x263c,
+      0x25ba,
+      0x25c4,
+      0x2195,
+      0x203c,
+      0x00b6,
+      0x00a7,
+      0x25ac,
+      0x21a8,
+      0x2191,
+      0x2193,
+      0x2192,
+      0x2190,
+      0x221f,
+      0x2194,
+      0x25b2,
+      0x25bc
+    };
+	
+    ucs2_to_nativecharset = iconv_open(nl_langinfo(CODESET), "UCS-2");
+    if (ucs2_to_nativecharset == (iconv_t) -1) {
+        fprintf(stderr, "Could not convert font glyphs from UCS-2: '%s'\n",
+                        strerror(errno));
+        exit(1);
+    }
+
+    nativecharset_to_ucs2 = iconv_open("UCS-2", nl_langinfo(CODESET));
+    if (nativecharset_to_ucs2 == (iconv_t) -1) {
+        fprintf(stderr, "Could not convert font glyphs to UCS-2: '%s'\n",
+                        strerror(errno));
+        exit(1);
+    }
+
+    /* Control characters */
+    for (i = 0; i <= 0x1F; i++) {
+        convert_ucs(i, control_characters[i], ucs2_to_nativecharset);
+    }
+
+    for (i = 0x20; i <= 0xFF; i++) {
+        convert_font(i);
+    }
+
+    /* DEL */
+    convert_ucs(0x7F, 0x2302, ucs2_to_nativecharset);
+
+    if (strcmp(nl_langinfo(CODESET), "UTF-8")) {
+        /* Non-Unicode capable, use termcap equivalents for those available */
+        for (i = 0; i <= 0xFF; i++) {
+            switch (get_ucs(vga_to_curses[i].chars[0], nativecharset_to_ucs2)) {
+            case 0x00a3:
+                vga_to_curses[i] = *WACS_STERLING;
+                break;
+            case 0x2591:
+                vga_to_curses[i] = *WACS_BOARD;
+                break;
+            case 0x2592:
+                vga_to_curses[i] = *WACS_CKBOARD;
+                break;
+            case 0x2502:
+                vga_to_curses[i] = *WACS_VLINE;
+                break;
+            case 0x2524:
+                vga_to_curses[i] = *WACS_RTEE;
+                break;
+            case 0x2510:
+                vga_to_curses[i] = *WACS_URCORNER;
+                break;
+            case 0x2514:
+                vga_to_curses[i] = *WACS_LLCORNER;
+                break;
+            case 0x2534:
+                vga_to_curses[i] = *WACS_BTEE;
+                break;
+            case 0x252c:
+                vga_to_curses[i] = *WACS_TTEE;
+                break;
+            case 0x251c:
+                vga_to_curses[i] = *WACS_LTEE;
+                break;
+            case 0x2500:
+                vga_to_curses[i] = *WACS_HLINE;
+                break;
+            case 0x253c:
+                vga_to_curses[i] = *WACS_PLUS;
+                break;
+            case 0x256c:
+                vga_to_curses[i] = *WACS_LANTERN;
+                break;
+            case 0x256a:
+                vga_to_curses[i] = *WACS_NEQUAL;
+                break;
+            case 0x2518:
+                vga_to_curses[i] = *WACS_LRCORNER;
+                break;
+            case 0x250c:
+                vga_to_curses[i] = *WACS_ULCORNER;
+                break;
+            case 0x2588:
+                vga_to_curses[i] = *WACS_BLOCK;
+                break;
+            case 0x03c0:
+                vga_to_curses[i] = *WACS_PI;
+                break;
+            case 0x00b1:
+                vga_to_curses[i] = *WACS_PLMINUS;
+                break;
+            case 0x2265:
+                vga_to_curses[i] = *WACS_GEQUAL;
+                break;
+            case 0x2264:
+                vga_to_curses[i] = *WACS_LEQUAL;
+                break;
+            case 0x00b0:
+                vga_to_curses[i] = *WACS_DEGREE;
+                break;
+            case 0x25a0:
+                vga_to_curses[i] = *WACS_BULLET;
+                break;
+            case 0x2666:
+                vga_to_curses[i] = *WACS_DIAMOND;
+                break;
+            case 0x2192:
+                vga_to_curses[i] = *WACS_RARROW;
+                break;
+            case 0x2190:
+                vga_to_curses[i] = *WACS_LARROW;
+                break;
+            case 0x2191:
+                vga_to_curses[i] = *WACS_UARROW;
+                break;
+            case 0x2193:
+                vga_to_curses[i] = *WACS_DARROW;
+                break;
+            case 0x23ba:
+                vga_to_curses[i] = *WACS_S1;
+                break;
+            case 0x23bb:
+                vga_to_curses[i] = *WACS_S3;
+                break;
+            case 0x23bc:
+                vga_to_curses[i] = *WACS_S7;
+                break;
+            case 0x23bd:
+                vga_to_curses[i] = *WACS_S9;
+                break;
+            }
+        }
+    }
+
+    iconv_close(ucs2_to_nativecharset);
+    iconv_close(nativecharset_to_ucs2);
+}
+#endif
+
 
 static void curses_setup(void)
 {
