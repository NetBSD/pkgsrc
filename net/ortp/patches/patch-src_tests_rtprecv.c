$NetBSD: patch-src_tests_rtprecv.c,v 1.1 2012/03/10 22:07:25 markd Exp $

Fix build with gcc 4.6

--- src/tests/rtprecv.c.orig	2012-02-13 09:13:43.992297823 +0000
+++ src/tests/rtprecv.c
@@ -162,9 +162,9 @@ int main(int argc, char*argv[])
 			if (err>0) stream_received=1;
 			/* this is to avoid to write to disk some silence before the first RTP packet is returned*/	
 			if ((stream_received) && (err>0)) {
-				size_t ret = fwrite(buffer,1,err,outfile);
+				fwrite(buffer,1,err,outfile);
 				if (sound_fd>0)
-					ret = write(sound_fd,buffer,err);
+					write(sound_fd,buffer,err);
 			}
 		}
 		ts+=160;
