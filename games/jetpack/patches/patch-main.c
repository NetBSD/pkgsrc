$NetBSD: patch-main.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- main.c.orig	2013-01-14 16:27:35.000000000 +0000
+++ main.c
@@ -90,7 +90,7 @@ main()
 				begin_timer();
 				while(paused) {
 					while(XPending(display) && !event_filter());
-					usleep(USECDELAY);
+					usleep(usecdelay);
 				}
 				while(XPending(display) && !event_filter());
 				update();
@@ -111,7 +111,7 @@ main()
 					busy, and you shouldn't be playing anyway.
 				*/
 				timer = get_timer();
-				if(timer < USECDELAY) usleep(USECDELAY - timer);
+				if(timer < usecdelay) usleep(usecdelay - timer);
 			}
 		}
 	}
