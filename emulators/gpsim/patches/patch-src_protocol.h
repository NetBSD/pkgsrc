$NetBSD: patch-src_protocol.h,v 1.1 2012/12/24 06:08:30 dholland Exp $

Remove any putc macro before defining a putc member function.
Required for building on DragonFly.

--- src/protocol.h~	2005-08-25 21:57:44.000000000 +0000
+++ src/protocol.h
@@ -101,6 +101,7 @@ public:
 
   void terminate();
 
+#undef putc /* in case it's a macro coming from stdio.h */
   void putc(char c)
   {
     if(index < size)
