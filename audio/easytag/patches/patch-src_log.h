$NetBSD: patch-src_log.h,v 1.1 2013/04/27 23:05:27 joerg Exp $

--- src/log.h.orig	2013-04-27 22:33:45.000000000 +0000
+++ src/log.h
@@ -48,7 +48,7 @@ GtkWidget *Create_Log_Area      (void);
 
 void       Log_Clean_Log_List   (void);
 
-void       Log_Print            (Log_Error_Type error_type, gchar const *format, ...);
+void       Log_Print            (Log_Error_Type error_type, gchar const *format, ...) G_GNUC_PRINTF(2, 3);
 
 
 #endif /* __LOG_H__ */
