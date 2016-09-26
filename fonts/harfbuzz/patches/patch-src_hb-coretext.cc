$NetBSD: patch-src_hb-coretext.cc,v 1.1 2016/09/26 11:30:42 jperkin Exp $

Provide compatibility define for older SDKs.

--- src/hb-coretext.cc.orig	2016-09-07 20:57:11.000000000 +0000
+++ src/hb-coretext.cc
@@ -152,6 +152,9 @@ create_ct_font (CGFontRef cg_font, CGFlo
    * operating system versions. Except for the emoji font, where _not_
    * reconfiguring the cascade list causes CoreText crashes. For details, see
    * crbug.com/549610 */
+#ifndef kCTVersionNumber10_10
+#define kCTVersionNumber10_10	0x00070000
+#endif
   if (&CTGetCoreTextVersion != NULL && CTGetCoreTextVersion() < kCTVersionNumber10_10) {
     CFStringRef fontName = CTFontCopyPostScriptName (ct_font);
     bool isEmojiFont = CFStringCompare (fontName, CFSTR("AppleColorEmoji"), 0) == kCFCompareEqualTo;
