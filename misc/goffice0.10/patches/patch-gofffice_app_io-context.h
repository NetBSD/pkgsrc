$NetBSD: patch-gofffice_app_io-context.h,v 1.1 2015/08/10 19:30:06 joerg Exp $

--- goffice/app/io-context.h.orig	2015-08-10 16:19:57.000000000 +0000
+++ goffice/app/io-context.h
@@ -43,7 +43,7 @@ void       go_io_progress_unset      (GO
 void go_io_context_set_num_files	(GOIOContext *ioc, guint count);
 void go_io_context_processing_file	(GOIOContext *ioc, char const *uri);
 void go_io_warning			(GOIOContext *ioc, char const *fmt, ...) G_GNUC_PRINTF (2, 3);
-void go_io_warning_varargs		(GOIOContext *ioc, char const *fmt, va_list args);
+void go_io_warning_varargs		(GOIOContext *ioc, char const *fmt, va_list args) G_GNUC_PRINTF (2, 0);
 void go_io_warning_unknown_font	(GOIOContext *ioc, char const *font_name);
 void go_io_warning_unknown_function	(GOIOContext *ioc, char const *funct_name);
 void go_io_warning_unsupported_feature	(GOIOContext *ioc, char const *feature);
