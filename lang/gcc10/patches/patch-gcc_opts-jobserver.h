$NetBSD: patch-gcc_opts-jobserver.h,v 1.1 2024/04/01 14:33:57 js Exp $

--- gcc/opts-jobserver.h.orig	2023-07-07 07:08:19.000000000 +0000
+++ gcc/opts-jobserver.h
@@ -30,17 +30,17 @@ struct jobserver_info
   jobserver_info ();
 
   /* Error message if there is a problem.  */
-  string error_msg = "";
+  string error_msg;
   /* Skipped MAKEFLAGS where --jobserver-auth is skipped.  */
-  string skipped_makeflags = "";
+  string skipped_makeflags;
   /* File descriptor for reading used for jobserver communication.  */
-  int rfd = -1;
+  int rfd;
   /* File descriptor for writing used for jobserver communication.  */
-  int wfd = -1;
+  int wfd;
   /* Named pipe path.  */
-  string pipe_path = "";
+  string pipe_path;
   /* Return true if jobserver is active.  */
-  bool is_active = false;
+  bool is_active;
 };
 
 #endif /* GCC_JOBSERVER_H */
