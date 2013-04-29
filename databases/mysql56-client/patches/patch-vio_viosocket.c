$NetBSD: patch-vio_viosocket.c,v 1.1 2013/04/29 21:16:58 joerg Exp $

--- vio/viosocket.c.orig	2013-04-28 13:51:01.000000000 +0000
+++ vio/viosocket.c
@@ -854,16 +854,16 @@ int vio_io_wait(Vio *vio, enum enum_vio_
   switch (event)
   {
   case VIO_IO_EVENT_READ:
-    ret= test(FD_ISSET(fd, &readfds));
+    ret= my_test(FD_ISSET(fd, &readfds));
     break;
   case VIO_IO_EVENT_WRITE:
   case VIO_IO_EVENT_CONNECT:
-    ret= test(FD_ISSET(fd, &writefds));
+    ret= my_test(FD_ISSET(fd, &writefds));
     break;
   }
 
   /* Error conditions pending? */
-  ret|= test(FD_ISSET(fd, &exceptfds));
+  ret|= my_test(FD_ISSET(fd, &exceptfds));
 
   /* Not a timeout, ensure that a condition was met. */
   DBUG_ASSERT(ret);
@@ -946,7 +946,7 @@ vio_socket_connect(Vio *vio, struct sock
 #else
       errno= error;
 #endif
-      ret= test(error);
+      ret= my_test(error);
     }
   }
 
@@ -957,7 +957,7 @@ vio_socket_connect(Vio *vio, struct sock
       DBUG_RETURN(TRUE);
   }
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
