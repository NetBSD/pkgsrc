$NetBSD: patch-src_icqface.cc,v 1.1 2021/12/19 02:44:20 dholland Exp $

Disable bogus test that makes contact entries located in the upper
half of memory gratuitously unusable.

--- src/icqface.cc~	2010-11-23 19:03:04.000000000 +0000
+++ src/icqface.cc
@@ -539,7 +539,7 @@ icqcontact *icqface::mainloop(int &actio
 	    g = 0;
 	}
 	
-	if((intptr_t) c < 100) c = 0;
+	/* if((intptr_t) c < 100) c = 0; */
 
 	if(i) {
 	    switch(action = extk) {
