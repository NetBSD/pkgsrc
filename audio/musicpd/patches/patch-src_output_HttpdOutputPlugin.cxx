$NetBSD: patch-src_output_HttpdOutputPlugin.cxx,v 1.1 2014/05/16 00:33:47 pho Exp $

Inlining this method results in the following error on Mach-O systems
(or at least on Darwin 9):

  {standard input}:1322:FATAL:symbol: __ZZN11HttpdOutput7SendTagEPK3TagE5types
  can't be a weak_definition (currently only supported in section of type
  coalesced)

--- src/output/HttpdOutputPlugin.cxx.orig	2014-05-16 00:08:45.000000000 +0000
+++ src/output/HttpdOutputPlugin.cxx
@@ -479,7 +479,7 @@ httpd_output_pause(struct audio_output *
 	}
 }
 
-inline void
+void
 HttpdOutput::SendTag(const Tag *tag)
 {
 	assert(tag != nullptr);
