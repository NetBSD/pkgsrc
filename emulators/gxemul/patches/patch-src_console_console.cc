$NetBSD: patch-src_console_console.cc,v 1.2 2017/07/16 16:36:09 christos Exp $

Change console_charavail() to return the number of characters available
in the FIFO instead of 0/1.

--- src/console/console.cc.orig	2014-08-17 04:45:15.000000000 -0400
+++ src/console/console.cc	2017-07-16 10:04:04.603287788 -0400
@@ -328,10 +328,19 @@
 }
 
 
+static int console_room_left_in_fifo(int handle)
+{
+	int roomLeftInFIFO = console_handles[handle].fifo_tail
+	    - console_handles[handle].fifo_head;
+	if (roomLeftInFIFO <= 0)
+		roomLeftInFIFO += CONSOLE_FIFO_LEN;
+	return roomLeftInFIFO;
+}
+
 /*
  *  console_charavail():
  *
- *  Returns 1 if a char is available in the fifo, 0 otherwise.
+ *  Returns the number of chararacters available in the fifo.
  */
 int console_charavail(int handle)
 {
@@ -342,9 +351,7 @@
 
 		// If adding more would lead to a full FIFO, then let's
 		// wait.
-		int roomLeftInFIFO = console_handles[handle].fifo_tail - console_handles[handle].fifo_head;
-		if (roomLeftInFIFO <= 0)
-			roomLeftInFIFO += CONSOLE_FIFO_LEN;
+		int roomLeftInFIFO = console_room_left_in_fifo(handle);
 		if (roomLeftInFIFO < (int)sizeof(ch) + 1)
 			break;
 
@@ -369,11 +376,7 @@
 		}
 	}
 
-	if (console_handles[handle].fifo_head ==
-	    console_handles[handle].fifo_tail)
-		return 0;
-
-	return 1;
+	return CONSOLE_FIFO_LEN - console_room_left_in_fifo(handle);
 }
 
 
