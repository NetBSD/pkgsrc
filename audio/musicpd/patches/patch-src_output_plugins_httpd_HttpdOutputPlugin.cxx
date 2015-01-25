$NetBSD: patch-src_output_plugins_httpd_HttpdOutputPlugin.cxx,v 1.1 2015/01/25 14:10:03 pho Exp $

Inlining this method results in the following error on Mach-O systems
(or at least on Darwin 9):

  {standard input}:1322:FATAL:symbol: __ZZN11HttpdOutput7SendTagEPK3TagE5types
  can't be a weak_definition (currently only supported in section of type
  coalesced)

This seems to be a bug in the compiler, not in MPD, but we aren't sure
what is really going on. The patch has been rejected by the upstream
for not knowing the actual cause.

http://bugs.musicpd.org/view.php?id=4059

--- src/output/plugins/httpd/HttpdOutputPlugin.cxx.orig	2014-10-24 22:28:53.000000000 +0000
+++ src/output/plugins/httpd/HttpdOutputPlugin.cxx
@@ -498,7 +498,7 @@ httpd_output_pause(AudioOutput *ao)
 	}
 }
 
-inline void
+void
 HttpdOutput::SendTag(const Tag *tag)
 {
 	assert(tag != nullptr);
