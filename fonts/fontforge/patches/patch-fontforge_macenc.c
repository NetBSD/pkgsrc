$NetBSD: patch-fontforge_macenc.c,v 1.2 2025/10/06 19:59:04 wiz Exp $

https://github.com/fontforge/fontforge/pull/5637

/scratch/fonts/fontforge/work/fontforge-20230101/fontforge/macenc.c: In function 'MacStrToUtf8':
/scratch/fonts/fontforge/work/fontforge-20230101/fontforge/macenc.c:1141:16: error: assignment to 'struct __tag_iconv_t **' from incompatible pointer type 'iconv_t' {aka 'struct __tag_iconv_t *'} [-Wincompatible-pointer-types]
 1141 |         toutf8 = iconv_open("UTF-8",enc->iconv_name!=NULL?enc->iconv_name:enc->enc_name);
      |                ^
/scratch/fonts/fontforge/work/fontforge-20230101/fontforge/macenc.c:1142:20: warning: comparison of distinct pointer types lacks a cast [-Wcompare-distinct-pointer-types]
 1142 |         if ( toutf8==(iconv_t) -1 || toutf8==NULL )
      |                    ^~
/scratch/fonts/fontforge/work/fontforge-20230101/fontforge/macenc.c:1148:15: error: passing argument 1 of 'iconv' from incompatible pointer type [-Wincompatible-pointer-types]
 1148 |         iconv(toutf8,&in,&inlen,&out,&outlen);
      |               ^~~~~~
      |               |
      |               struct __tag_iconv_t **

--- fontforge/macenc.c.orig	2025-10-06 19:47:44.459616789 +0000
+++ fontforge/macenc.c
@@ -1132,7 +1132,7 @@ return( NULL );
 					    macenc==sm_korean ? "EUC-KR" :
 			                    macenc==sm_tradchinese ? "Big5" :
 			                      "EUC-CN" );
-	iconv_t *toutf8;
+	iconv_t toutf8;
 	ICONV_CONST char *in;
 	char *out;
 	size_t inlen, outlen;
