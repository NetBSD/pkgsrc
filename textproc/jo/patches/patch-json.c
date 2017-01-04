$NetBSD: patch-json.c,v 1.1 2017/01/04 12:44:59 fhajny Exp $

Backport a namespace conflict fix from trunk.

https://github.com/jpmens/jo/commit/2bedfd486f8f4a79b1865e370e6c858eb04257f5

--- json.c.orig	2016-03-10 10:49:34.000000000 +0000
+++ json.c
@@ -131,7 +131,7 @@ static void sb_free(SB *sb)
  * Type for Unicode codepoints.
  * We need our own because wchar_t might be 16 bits.
  */
-typedef uint32_t uchar_t;
+typedef uint32_t js_uchar_t;
 
 /*
  * Validate a single UTF-8 character starting at @s.
@@ -228,7 +228,7 @@ static bool utf8_validate(const char *s)
  * This function assumes input is valid UTF-8,
  * and that there are enough characters in front of @s.
  */
-static int utf8_read_char(const char *s, uchar_t *out)
+static int utf8_read_char(const char *s, js_uchar_t *out)
 {
 	const unsigned char *c = (const unsigned char*) s;
 	
@@ -240,21 +240,21 @@ static int utf8_read_char(const char *s,
 		return 1;
 	} else if (c[0] <= 0xDF) {
 		/* C2..DF (unless input is invalid) */
-		*out = ((uchar_t)c[0] & 0x1F) << 6 |
-		       ((uchar_t)c[1] & 0x3F);
+		*out = ((js_uchar_t)c[0] & 0x1F) << 6 |
+		       ((js_uchar_t)c[1] & 0x3F);
 		return 2;
 	} else if (c[0] <= 0xEF) {
 		/* E0..EF */
-		*out = ((uchar_t)c[0] &  0xF) << 12 |
-		       ((uchar_t)c[1] & 0x3F) << 6  |
-		       ((uchar_t)c[2] & 0x3F);
+		*out = ((js_uchar_t)c[0] &  0xF) << 12 |
+		       ((js_uchar_t)c[1] & 0x3F) << 6  |
+		       ((js_uchar_t)c[2] & 0x3F);
 		return 3;
 	} else {
 		/* F0..F4 (unless input is invalid) */
-		*out = ((uchar_t)c[0] &  0x7) << 18 |
-		       ((uchar_t)c[1] & 0x3F) << 12 |
-		       ((uchar_t)c[2] & 0x3F) << 6  |
-		       ((uchar_t)c[3] & 0x3F);
+		*out = ((js_uchar_t)c[0] &  0x7) << 18 |
+		       ((js_uchar_t)c[1] & 0x3F) << 12 |
+		       ((js_uchar_t)c[2] & 0x3F) << 6  |
+		       ((js_uchar_t)c[3] & 0x3F);
 		return 4;
 	}
 }
@@ -267,7 +267,7 @@ static int utf8_read_char(const char *s,
  *
  * This function will write up to 4 bytes to @out.
  */
-static int utf8_write_char(uchar_t unicode, char *out)
+static int utf8_write_char(js_uchar_t unicode, char *out)
 {
 	unsigned char *o = (unsigned char*) out;
 	
@@ -304,10 +304,10 @@ static int utf8_write_char(uchar_t unico
  * @uc should be 0xD800..0xDBFF, and @lc should be 0xDC00..0xDFFF.
  * If they aren't, this function returns false.
  */
-static bool from_surrogate_pair(uint16_t uc, uint16_t lc, uchar_t *unicode)
+static bool from_surrogate_pair(uint16_t uc, uint16_t lc, js_uchar_t *unicode)
 {
 	if (uc >= 0xD800 && uc <= 0xDBFF && lc >= 0xDC00 && lc <= 0xDFFF) {
-		*unicode = 0x10000 + ((((uchar_t)uc & 0x3FF) << 10) | (lc & 0x3FF));
+		*unicode = 0x10000 + ((((js_uchar_t)uc & 0x3FF) << 10) | (lc & 0x3FF));
 		return true;
 	} else {
 		return false;
@@ -319,9 +319,9 @@ static bool from_surrogate_pair(uint16_t
  *
  * @unicode must be U+10000..U+10FFFF.
  */
-static void to_surrogate_pair(uchar_t unicode, uint16_t *uc, uint16_t *lc)
+static void to_surrogate_pair(js_uchar_t unicode, uint16_t *uc, uint16_t *lc)
 {
-	uchar_t n;
+	js_uchar_t n;
 	
 	assert(unicode >= 0x10000 && unicode <= 0x10FFFF);
 	
@@ -844,7 +844,7 @@ bool parse_string(const char **sp, char
 				case 'u':
 				{
 					uint16_t uc, lc;
-					uchar_t unicode;
+					js_uchar_t unicode;
 					
 					if (!parse_hex16(&s, &uc))
 						goto failed;
