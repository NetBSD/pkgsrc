$NetBSD: patch-src_tcpip.cpp,v 1.1 2017/07/04 13:50:42 jperkin Exp $

std::perror doesn't always support varargs.

--- src/tcpip.cpp.orig	2015-08-12 01:28:53.000000000 +0000
+++ src/tcpip.cpp
@@ -145,7 +145,8 @@ void tcpip::close_file()
 	    tstimes[i].tv_nsec = times[i].tv_usec * 1000;
 	}
 	if(futimens(fd,tstimes)){
-	    perror("futimens(fd=%d)",fd);
+	    fprintf(stderr,"%s: futimens(fd=%d)\n",strerror(errno),fd);
+	    abort();
 	}
 #endif
 	close(fd);
