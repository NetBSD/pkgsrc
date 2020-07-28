$NetBSD: patch-core_src_findlib_find__one.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Simplify UF_NODUMP test

--- core/src/findlib/find_one.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/findlib/find_one.cc
@@ -206,7 +206,7 @@ static bool VolumeHasAttrlist(const char
  */
 static inline bool no_dump(JobControlRecord* jcr, FindFilesPacket* ff_pkt)
 {
-#if defined(HAVE_CHFLAGS) && defined(UF_NODUMP)
+#if defined(UF_NODUMP)
   if (BitIsSet(FO_HONOR_NODUMP, ff_pkt->flags) &&
       (ff_pkt->statp.st_flags & UF_NODUMP)) {
     Jmsg(jcr, M_INFO, 1, _("     NODUMP flag set - will not process %s\n"),
