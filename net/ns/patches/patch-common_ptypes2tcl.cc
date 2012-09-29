$NetBSD: patch-common_ptypes2tcl.cc,v 1.1 2012/09/29 06:17:30 dholland Exp $

Suppress const warnings. Required by the common/packet.h patch.
While here, use tolower() correctly.

--- common/ptypes2tcl.cc.orig	2008-04-01 02:00:25.000000000 +0000
+++ common/ptypes2tcl.cc
@@ -10,7 +10,7 @@
 #define TCL2C_INT
 #endif
 
-char** p_info::name_;
+const char** p_info::name_;
 unsigned int p_info::nPkt_ = 0;
 PacketClassifier *p_info::pc_ = 0;
 int p_info::addPacket(char *name)
@@ -26,7 +26,7 @@ int p_info::addPacket(char *name)
 }
 
 void
-printLine(char *s) {
+printLine(const char *s) {
 #ifdef TCL2C_INT
 	for (unsigned int i = 0; i < strlen(s); i++) 
 		if ((i > 0) && ((i % 20) == 0))
@@ -43,7 +43,7 @@ char *
 lcase(const char *s) {
 	static char charbuf[512];
 	char* to = charbuf;
-	while ((*to++ = tolower(*s++)))
+	while ((*to++ = tolower((unsigned char)*s++)))
 		/* NOTHING */;
 	*to = '\0';
 	return charbuf;
