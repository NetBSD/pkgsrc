$NetBSD: patch-random_rndunix.c,v 1.1.2.2 2015/03/09 19:37:10 tron Exp $

From: Werner Koch <wk@gnupg.org>
Date: Mon, 5 Jan 2015 18:38:29 +0000 (+0100)
Subject: random: Silent warning under NetBSD using rndunix
X-Git-Url: http://git.gnupg.org/cgi-bin/gitweb.cgi?p=libgcrypt.git;a=commitdiff_plain;h=817472358a093438e802380caecf7139406400cf;hp=8c5eee51d9a25b143e41ffb7ff4a6b2a29b82d83

random: Silent warning under NetBSD using rndunix

* random/rndunix.c (STDERR_FILENO): Define if needed.
(start_gatherer): Re-open standard descriptors.  Fix an
unsigned/signed pointer warning.
--

GnuPG-bug-id: 1702

--- random/rndunix.c.orig	2013-12-12 14:15:04.000000000 +0000
+++ random/rndunix.c
@@ -144,6 +144,9 @@
 #ifndef STDOUT_FILENO
 #define STDOUT_FILENO 1
 #endif
+#ifndef STDERR_FILENO
+#define STDERR_FILENO 2
+#endif
 
 #define GATHER_BUFSIZE		49152	/* Usually about 25K are filled */
 
@@ -766,13 +769,27 @@ start_gatherer( int pipefd )
 
     fclose(stderr);		/* Arrghh!!  It's Stuart code!! */
 
+    /* Mary goes to Berkeley: NetBSD emits warnings if the standard
+       descriptors are not open when running setuid program.  Thus we
+       connect them to the bitbucket if they are not already open.  */
+    {
+      struct stat statbuf;
+
+      if (fstat (STDIN_FILENO, &statbuf) == -1 && errno == EBADF)
+        open ("/dev/null",O_RDONLY);
+      if (fstat (STDOUT_FILENO, &statbuf) == -1 && errno == EBADF)
+        open ("/dev/null",O_WRONLY);
+      if (fstat (STDERR_FILENO, &statbuf) == -1 && errno == EBADF)
+        open ("/dev/null",O_WRONLY);
+    }
+
     for(;;) {
 	GATHER_MSG msg;
 	size_t nbytes;
 	const char *p;
 
 	msg.usefulness = slow_poll( dbgfp, dbgall, &nbytes );
-	p = gather_buffer;
+	p = (const char*)gather_buffer;
 	while( nbytes ) {
 	    msg.ndata = nbytes > sizeof(msg.data)? sizeof(msg.data) : nbytes;
 	    memcpy( msg.data, p, msg.ndata );
