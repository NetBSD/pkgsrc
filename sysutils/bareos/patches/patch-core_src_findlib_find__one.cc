$NetBSD: patch-core_src_findlib_find__one.cc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	simplify UF_NODUMP test

--- core/src/findlib/find_one.cc.orig	2021-01-22 13:22:58.585014513 +0000
+++ core/src/findlib/find_one.cc
@@ -208,7 +208,7 @@ static bool VolumeHasAttrlist(const char
  */
 static inline bool no_dump(JobControlRecord* jcr, FindFilesPacket* ff_pkt)
 {
-#if defined(HAVE_CHFLAGS) && defined(UF_NODUMP)
+#if defined(UF_NODUMP)
   if (BitIsSet(FO_HONOR_NODUMP, ff_pkt->flags)
       && (ff_pkt->statp.st_flags & UF_NODUMP)) {
     Jmsg(jcr, M_INFO, 1, _("     NODUMP flag set - will not process %s\n"),
