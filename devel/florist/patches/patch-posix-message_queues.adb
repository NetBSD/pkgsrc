$NetBSD: patch-posix-message_queues.adb,v 1.3 2004/06/30 11:23:43 shannonjr Exp $

--- posix-message_queues.adb.orig	2002-10-24 02:03:52.000000000 -0600
+++ posix-message_queues.adb
@@ -350,7 +350,7 @@ package body POSIX.Message_Queues is
             size_t ((Message'Size + char'Size - 1) / char'Size),
             unsigned (Priority));
          Check_NNeg_And_Restore_Signals
-           (int (Result), Masked_Signals, Old_Mask'Unchecked_Access);
+           (Result, Masked_Signals, Old_Mask'Unchecked_Access);
       end Send;
 
       ---------------
