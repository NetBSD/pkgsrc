$NetBSD: patch-ext_standard_crypt__blowfish.c,v 1.2 2011/06/22 09:54:35 taca Exp $

- Fix potential security problem by char signedness processing:
  http://www.openwall.com/lists/oss-security/2011/06/20/2

  Dereived from revision 1.11 change of http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/glibc/crypt_blowfish/crypt_blowfish.c.

--- ext/standard/crypt_blowfish.c.orig	2010-02-21 23:47:14.000000000 +0000
+++ ext/standard/crypt_blowfish.c
@@ -7,6 +7,7 @@
  * cracking removed.
  *
  * Written by Solar Designer <solar at openwall.com> in 1998-2002 and
+ * placed in the public domain.  Quick self-test added in 2011 and also
  * placed in the public domain.
  *
  * There's absolutely no warranty.
@@ -51,6 +52,13 @@
 #define __CONST __const
 #endif
 
+/*
+ * Please keep this enabled.  We really don't want incompatible hashes to be
+ * produced.  The performance cost of this quick self-test is around 0.6% at
+ * the "$2a$08" setting.
+ */
+#define BF_SELF_TEST
+
 #ifdef __i386__
 #define BF_ASM				0
 #define BF_SCALE			1
@@ -63,6 +71,7 @@
 #endif
 
 typedef unsigned int BF_word;
+typedef signed int BF_word_signed;
 
 /* Number of Blowfish rounds, this is also hardcoded into a few places */
 #define BF_N				16
@@ -555,7 +564,8 @@ static void BF_swap(BF_word *x, int coun
 	} while (ptr < &data.ctx.S[3][0xFF]);
 #endif
 
-static void BF_set_key(__CONST char *key, BF_key expanded, BF_key initial)
+static void BF_set_key(__CONST char *key, BF_key expanded, BF_key initial,
+    int sign_extension_bug)
 {
 	__CONST char *ptr = key;
 	int i, j;
@@ -565,7 +575,10 @@ static void BF_set_key(__CONST char *key
 		tmp = 0;
 		for (j = 0; j < 4; j++) {
 			tmp <<= 8;
-			tmp |= *ptr;
+			if (sign_extension_bug)
+				tmp |= (BF_word_signed)(signed char)*ptr;
+			else
+				tmp |= (unsigned char)*ptr;
 
 			if (!*ptr) ptr = key; else ptr++;
 		}
@@ -575,8 +588,9 @@ static void BF_set_key(__CONST char *key
 	}
 }
 
-char *php_crypt_blowfish_rn(__CONST char *key, __CONST char *setting,
-	char *output, int size)
+static char *BF_crypt(__CONST char *key, __CONST char *setting,
+	char *output, int size,
+	BF_word min)
 {
 #if BF_ASM
 	extern void _BF_body_r(BF_ctx *ctx);
@@ -602,7 +616,7 @@ char *php_crypt_blowfish_rn(__CONST char
 
 	if (setting[0] != '$' ||
 	    setting[1] != '2' ||
-	    setting[2] != 'a' ||
+	    (setting[2] != 'a' && setting[2] != 'x') ||
 	    setting[3] != '$' ||
 	    setting[4] < '0' || setting[4] > '3' ||
 	    setting[5] < '0' || setting[5] > '9' ||
@@ -613,7 +627,7 @@ char *php_crypt_blowfish_rn(__CONST char
 	}
 
 	count = (BF_word)1 << ((setting[4] - '0') * 10 + (setting[5] - '0'));
-	if (count < 16 || BF_decode(data.binary.salt, &setting[7], 16)) {
+	if (count < min || BF_decode(data.binary.salt, &setting[7], 16)) {
 		clean(data.binary.salt, sizeof(data.binary.salt));
 		__set_errno(EINVAL);
 		return NULL;
@@ -621,7 +635,7 @@ char *php_crypt_blowfish_rn(__CONST char
 
 	BF_swap(data.binary.salt, 4);
 
-	BF_set_key(key, data.expanded_key, data.ctx.P);
+	BF_set_key(key, data.expanded_key, data.ctx.P, setting[2] == 'x');
 
 	memcpy(data.ctx.S, BF_init_state.S, sizeof(data.ctx.S));
 
@@ -721,14 +735,59 @@ char *php_crypt_blowfish_rn(__CONST char
 	BF_encode(&output[7 + 22], data.binary.output, 23);
 	output[7 + 22 + 31] = '\0';
 
+#ifndef BF_SELF_TEST
 /* Overwrite the most obvious sensitive data we have on the stack. Note
  * that this does not guarantee there's no sensitive data left on the
  * stack and/or in registers; I'm not aware of portable code that does. */
 	clean(&data, sizeof(data));
+#endif
 
 	return output;
 }
 
+char *php_crypt_blowfish_rn(__CONST char *key, __CONST char *setting,
+	char *output, int size)
+{
+#ifdef BF_SELF_TEST
+	__CONST char *test_key = "8b \xd0\xc1\xd2\xcf\xcc\xd8";
+	__CONST char *test_2a =
+	    "$2a$00$abcdefghijklmnopqrstuui1D709vfamulimlGcq0qq3UvuUasvEa"
+	    "\0"
+	    "canary";
+	__CONST char *test_2x =
+	    "$2x$00$abcdefghijklmnopqrstuuVUrPmXD6q/nVSSp7pNDhCR9071IfIRe"
+	    "\0"
+	    "canary";
+	__CONST char *test_hash, *p;
+	int ok;
+	char buf[7 + 22 + 31 + 1 + 6 + 1];
+
+	output = BF_crypt(key, setting, output, size, 16);
+
+/* Do a quick self-test.  This also happens to overwrite BF_crypt()'s data. */
+	test_hash = (setting[2] == 'x') ? test_2x : test_2a;
+	memcpy(buf, test_hash, sizeof(buf));
+	memset(buf, -1, sizeof(buf) - (6 + 1)); /* keep "canary" only */
+	p = BF_crypt(test_key, test_hash, buf, sizeof(buf) - 6, 1);
+
+	ok = (p == buf && !memcmp(p, test_hash, sizeof(buf)));
+
+/* This could reveal what hash type we were using last.  Unfortunately, we
+ * can't reliably clean the test_hash pointer. */
+	clean(&buf, sizeof(buf));
+
+	if (ok)
+		return output;
+
+/* Should not happen */
+	__set_errno(EINVAL); /* pretend we don't support this hash type */
+	return NULL;
+#else
+#warning Self-test is disabled, please enable
+	return BF_crypt(key, setting, output, size, 16);
+#endif
+}
+
 char *php_crypt_gensalt_blowfish_rn(unsigned long count,
 	__CONST char *input, int size, char *output, int output_size)
 {
