$NetBSD: patch-richmail_richlex.h,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.


--- richmail/richlex.h.orig	1993-08-23 15:48:26.000000000 -0700
+++ richmail/richlex.h	2025-10-11 17:43:32.409497968 -0700
@@ -101,7 +101,7 @@ extern	int (*RichtextPutc) ();
 /*
  * Reset the richtext parsing mechanism.
  */
-extern	richtextreset();
+extern void	richtextreset();
 
 /*
  * Get the next token from the input stream.  RICHTEXT_COMMAND
@@ -123,7 +123,7 @@ extern	RCHAR	richtextlex( /* void *file,
  * "RichtextPutc" function as the second argument, and "inparam"
  * is passed to "richtextlex" during parsing.
  */
-extern	richtextcorrect( /* void *inparam,void *outparam,int TextEnriched */ );
+extern void	richtextcorrect( /* void *inparam,void *outparam,int TextEnriched */ );
 
 #define	RICH_ENC_US_ASCII	0	/* US-ASCII encoding: one-byte */
 #define	RICH_ENC_JP_ASCII	1	/* JP-ASCII encoding: one-byte */
@@ -143,7 +143,7 @@ extern	int	RichtextCharEncoding;
  * Change the encoding used for characters not present in
  * richtext command sequences.
  */
-extern	richtextencoding( /* int encoding */ );
+extern void	richtextencoding( /* int encoding */ );
 
 /*
  * Define a number of macros for decoding multi-byte character
