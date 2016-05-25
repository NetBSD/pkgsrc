$NetBSD$

Since this is built with C90, and %zu isn't supported then, cast
the size_t argument to unsigned long to match the format.
https://bugzilla.gnome.org/show_bug.cgi?id=766839

--- xmlIO.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ xmlIO.c
@@ -1674,7 +1674,7 @@ xmlZMemBuffExtend( xmlZMemBuffPtr buff, 
 	xmlStrPrintf(msg, 500,
 		    "xmlZMemBuffExtend:  %s %lu bytes.\n",
 		    "Allocation failure extending output buffer to",
-		    new_size );
+		    (unsigned long)new_size );
 	xmlIOErr(XML_IO_WRITE, (const char *) msg);
     }
 
