$NetBSD: patch-common_packet.h,v 1.1 2012/09/29 06:17:30 dholland Exp $

Suppress immensely noisy const warnings.

--- common/packet.h.orig	2008-04-01 02:00:25.000000000 +0000
+++ common/packet.h
@@ -272,7 +272,7 @@ public:
 	{
 		if(nPkt_ >= PT_NTYPE+1)
 		        return;
-		char **nameNew = new char*[PT_NTYPE+1];
+		const char **nameNew = new const char*[PT_NTYPE+1];
 		for(unsigned int i = (unsigned int)PT_SMAC+1; i < nPkt_; i++)
 		{
 		        nameNew[i] = name_[i];
@@ -391,7 +391,7 @@ public:
 
 	}
 private:
-	static char** name_;
+	static const char** name_;
 	static unsigned int nPkt_;
 	static PacketClassifier *pc_;
 };
