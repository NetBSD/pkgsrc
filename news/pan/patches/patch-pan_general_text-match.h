$NetBSD: patch-pan_general_text-match.h,v 1.4 2022/04/03 19:33:11 rhialto Exp $

Avoid clash with host defined ERR (on SunOS)

--- pan/general/text-match.h.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/general/text-match.h
@@ -108,7 +108,7 @@ private:
       class PcreInfo;
       mutable PcreInfo * _pcre_info;
 
-      enum PcreState { NEED_COMPILE, COMPILED, ERR };
+      enum PcreState { NEED_COMPILE, COMPILED, PCRE_ERR };
       mutable PcreState _pcre_state;
 
 public:
