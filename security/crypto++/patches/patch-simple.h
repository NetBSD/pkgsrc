$NetBSD: patch-simple.h,v 1.1 2012/04/17 17:46:31 joerg Exp $

--- simple.h.orig	2012-04-17 15:39:30.000000000 +0000
+++ simple.h
@@ -125,7 +125,7 @@ public:
 	bool Flush(bool hardFlush, int propagation=-1, bool blocking=true)
 		{return ChannelFlush(this->NULL_CHANNEL, hardFlush, propagation, blocking);}
 	bool MessageSeriesEnd(int propagation=-1, bool blocking=true)
-		{return ChannelMessageSeriesEnd(this->NULL_CHANNEL, propagation, blocking);}
+		{return this->ChannelMessageSeriesEnd(this->NULL_CHANNEL, propagation, blocking);}
 	byte * CreatePutSpace(size_t &size)
 		{return ChannelCreatePutSpace(this->NULL_CHANNEL, size);}
 	size_t Put2(const byte *begin, size_t length, int messageEnd, bool blocking)
