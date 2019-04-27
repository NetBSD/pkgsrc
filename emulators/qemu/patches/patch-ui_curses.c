$NetBSD: patch-ui_curses.c,v 1.3 2019/04/27 18:00:46 kamil Exp $

 * fix compatibility with NetBSD curses(3)

https://patchwork.ozlabs.org/patch/1092056/

 * fix portability of iconv(3) usage

https://patchwork.ozlabs.org/patch/1092057/

--- ui/curses.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ ui/curses.c
@@ -66,20 +66,22 @@ static void curses_update(DisplayChangeL
 {
     console_ch_t *line;
     cchar_t curses_line[width];
+    wchar_t wch[CCHARW_MAX];
+    attr_t attrs;
+    short colors;
+    int ret;
 
     line = screen + y * width;
     for (h += y; y < h; y ++, line += width) {
         for (x = 0; x < width; x++) {
             chtype ch = line[x] & 0xff;
             chtype at = line[x] & ~0xff;
-            if (vga_to_curses[ch].chars[0]) {
-                curses_line[x] = vga_to_curses[ch];
-            } else {
-                curses_line[x] = (cchar_t) {
-                    .chars[0] = ch,
-                };
+            ret = getcchar(&vga_to_curses[ch], wch, &attrs, &colors, NULL);
+            if (ret == ERR || wch[0] == 0) {
+                wch[0] = ch;
+                wch[1] = 0;
             }
-            curses_line[x].attr |= at;
+            setcchar(&curses_line[x], wch, at, 0, NULL);
         }
         mvwadd_wchnstr(screenpad, y, 0, curses_line, width);
     }
@@ -400,65 +402,106 @@ static void curses_atexit(void)
     endwin();
 }
 
+/*
+ * In the following:
+ * - fch is the font glyph number
+ * - uch is the unicode value
+ * - wch is the wchar_t value (may not be unicode, e.g. on BSD/solaris)
+ * - mbch is the native local-dependent multibyte representation
+ */
+
 /* Setup wchar glyph for one UCS-2 char */
-static void convert_ucs(int glyph, uint16_t ch, iconv_t conv)
+static void convert_ucs(unsigned char fch, uint16_t uch, iconv_t conv)
 {
-    wchar_t wch;
-    char *pch, *pwch;
-    size_t sch, swch;
-
-    pch = (char *) &ch;
-    pwch = (char *) &wch;
-    sch = sizeof(ch);
-    swch = sizeof(wch);
-
-    if (iconv(conv, &pch, &sch, &pwch, &swch) == (size_t) -1) {
-        fprintf(stderr, "Could not convert 0x%04x from UCS-2 to WCHAR_T: %s\n",
-                        ch, strerror(errno));
-    } else {
-        vga_to_curses[glyph].chars[0] = wch;
+    char mbch[MB_CUR_MAX];
+    wchar_t wch[2];
+    char *puch, *pmbch;
+    size_t such, smbch;
+
+    puch = (char *) &uch;
+    pmbch = (char *) mbch;
+    such = sizeof(uch);
+    smbch = sizeof(mbch);
+
+    if (iconv(conv, &puch, &such, &pmbch, &smbch) == (size_t) -1) {
+        fprintf(stderr, "Could not convert 0x%04x "
+                        "from UCS-2 to a multibyte character: %s\n",
+                        uch, strerror(errno));
+        return;
+    }
+
+    if (mbtowc(&wch[0], mbch, sizeof(mbch) - smbch) == -1) {
+        fprintf(stderr, "Could not convert 0x%04x "
+                        "from a multibyte character to wchar_t: %s\n",
+                        uch, strerror(errno));
+        return;
     }
+
+    wch[1] = 0;
+    setcchar(&vga_to_curses[fch], wch, 0, 0, NULL);
 }
 
 /* Setup wchar glyph for one font character */
-static void convert_font(unsigned char ch, iconv_t conv)
+static void convert_font(unsigned char fch, iconv_t conv)
 {
-    wchar_t wch;
-    char *pch, *pwch;
-    size_t sch, swch;
-
-    pch = (char *) &ch;
-    pwch = (char *) &wch;
-    sch = sizeof(ch);
-    swch = sizeof(wch);
-
-    if (iconv(conv, &pch, &sch, &pwch, &swch) == (size_t) -1) {
-        fprintf(stderr, "Could not convert 0x%02x from %s to WCHAR_T: %s\n",
-                        ch, font_charset, strerror(errno));
-    } else {
-        vga_to_curses[ch].chars[0] = wch;
+    char mbch[MB_CUR_MAX];
+    wchar_t wch[2];
+    char *pfch, *pmbch;
+    size_t sfch, smbch;
+
+    pfch = (char *) &fch;
+    pmbch = (char *) &mbch;
+    sfch = sizeof(fch);
+    smbch = sizeof(mbch);
+
+    if (iconv(conv, &pfch, &sfch, &pmbch, &smbch) == (size_t) -1) {
+        fprintf(stderr, "Could not convert font glyph 0x%02x "
+                        "from %s to a multibyte character: %s\n",
+                        fch, font_charset, strerror(errno));
+        return;
+    }
+
+    if (mbtowc(&wch[0], mbch, sizeof(mbch) - smbch) == -1) {
+        fprintf(stderr, "Could not convert font glyph 0x%02x "
+                        "from a multibyte character to wchar_t: %s\n",
+                        fch, strerror(errno));
+        return;
     }
+
+    wch[1] = 0;
+    setcchar(&vga_to_curses[fch], wch, 0, 0, NULL);
 }
 
 /* Convert one wchar to UCS-2 */
 static uint16_t get_ucs(wchar_t wch, iconv_t conv)
 {
-    uint16_t ch;
-    char *pch, *pwch;
-    size_t sch, swch;
-
-    pch = (char *) &ch;
-    pwch = (char *) &wch;
-    sch = sizeof(ch);
-    swch = sizeof(wch);
-
-    if (iconv(conv, &pwch, &swch, &pch, &sch) == (size_t) -1) {
-        fprintf(stderr, "Could not convert 0x%02lx from WCHAR_T to UCS-2: %s\n",
-                (unsigned long)wch, strerror(errno));
+    char mbch[MB_CUR_MAX];
+    uint16_t uch;
+    char *pmbch, *puch;
+    size_t smbch, such;
+    int ret;
+
+    ret = wctomb(mbch, wch);
+    if (ret == -1) {
+        fprintf(stderr, "Could not convert 0x%04x "
+                        "from wchar_t to a multibyte character: %s\n",
+                        wch, strerror(errno));
+        return 0xFFFD;
+    }
+
+    pmbch = (char *) mbch;
+    puch = (char *) &uch;
+    smbch = ret;
+    such = sizeof(uch);
+
+    if (iconv(conv, &pmbch, &smbch, &puch, &such) == (size_t) -1) {
+        fprintf(stderr, "Could not convert 0x%04x "
+                        "from a multibyte character to UCS-2 : %s\n",
+                        wch, strerror(errno));
         return 0xFFFD;
     }
 
-    return ch;
+    return uch;
 }
 
 /*
@@ -466,6 +509,11 @@ static uint16_t get_ucs(wchar_t wch, ico
  */
 static void font_setup(void)
 {
+    iconv_t ucs2_to_nativecharset;
+    iconv_t nativecharset_to_ucs2;
+    iconv_t font_conv;
+    int i;
+
     /*
      * Control characters are normally non-printable, but VGA does have
      * well-known glyphs for them.
@@ -505,30 +553,25 @@ static void font_setup(void)
       0x25bc
     };
 
-    iconv_t ucs_to_wchar_conv;
-    iconv_t wchar_to_ucs_conv;
-    iconv_t font_conv;
-    int i;
-
-    ucs_to_wchar_conv = iconv_open("WCHAR_T", "UCS-2");
-    if (ucs_to_wchar_conv == (iconv_t) -1) {
+    ucs2_to_nativecharset = iconv_open(nl_langinfo(CODESET), "UCS-2");
+    if (ucs2_to_nativecharset == (iconv_t) -1) {
         fprintf(stderr, "Could not convert font glyphs from UCS-2: '%s'\n",
                         strerror(errno));
         exit(1);
     }
 
-    wchar_to_ucs_conv = iconv_open("UCS-2", "WCHAR_T");
-    if (wchar_to_ucs_conv == (iconv_t) -1) {
-        iconv_close(ucs_to_wchar_conv);
+    nativecharset_to_ucs2 = iconv_open("UCS-2", nl_langinfo(CODESET));
+    if (nativecharset_to_ucs2 == (iconv_t) -1) {
+        iconv_close(ucs2_to_nativecharset);
         fprintf(stderr, "Could not convert font glyphs to UCS-2: '%s'\n",
                         strerror(errno));
         exit(1);
     }
 
-    font_conv = iconv_open("WCHAR_T", font_charset);
+    font_conv = iconv_open(nl_langinfo(CODESET), font_charset);
     if (font_conv == (iconv_t) -1) {
-        iconv_close(ucs_to_wchar_conv);
-        iconv_close(wchar_to_ucs_conv);
+        iconv_close(ucs2_to_nativecharset);
+        iconv_close(nativecharset_to_ucs2);
         fprintf(stderr, "Could not convert font glyphs from %s: '%s'\n",
                         font_charset, strerror(errno));
         exit(1);
@@ -536,7 +579,7 @@ static void font_setup(void)
 
     /* Control characters */
     for (i = 0; i <= 0x1F; i++) {
-        convert_ucs(i, control_characters[i], ucs_to_wchar_conv);
+        convert_ucs(i, control_characters[i], ucs2_to_nativecharset);
     }
 
     for (i = 0x20; i <= 0xFF; i++) {
@@ -544,12 +587,21 @@ static void font_setup(void)
     }
 
     /* DEL */
-    convert_ucs(0x7F, 0x2302, ucs_to_wchar_conv);
+    convert_ucs(0x7F, 0x2302, ucs2_to_nativecharset);
 
     if (strcmp(nl_langinfo(CODESET), "UTF-8")) {
         /* Non-Unicode capable, use termcap equivalents for those available */
         for (i = 0; i <= 0xFF; i++) {
-            switch (get_ucs(vga_to_curses[i].chars[0], wchar_to_ucs_conv)) {
+            wchar_t wch[CCHARW_MAX];
+            attr_t attr;
+            short color;
+            int ret;
+
+            ret = getcchar(&vga_to_curses[i], wch, &attr, &color, NULL);
+            if (ret == ERR)
+                continue;
+
+            switch (get_ucs(wch[0], nativecharset_to_ucs2)) {
             case 0x00a3:
                 vga_to_curses[i] = *WACS_STERLING;
                 break;
@@ -649,8 +701,8 @@ static void font_setup(void)
             }
         }
     }
-    iconv_close(ucs_to_wchar_conv);
-    iconv_close(wchar_to_ucs_conv);
+    iconv_close(ucs2_to_nativecharset);
+    iconv_close(nativecharset_to_ucs2);
     iconv_close(font_conv);
 }
 
