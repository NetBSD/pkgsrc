$NetBSD: patch-goffice_app_error-info.h,v 1.1 2015/08/10 19:30:06 joerg Exp $

--- goffice/app/error-info.h.orig	2015-08-10 16:17:07.000000000 +0000
+++ goffice/app/error-info.h
@@ -16,7 +16,7 @@ GOErrorInfo *go_error_info_new_str			(ch
 GOErrorInfo *go_error_info_new_printf		(char const *msg_format, ...) G_GNUC_PRINTF (1, 2);
 GOErrorInfo *go_error_info_new_vprintf		(GOSeverity severity,
 						 char const *msg_format,
-						 va_list args);
+						 va_list args) G_GNUC_PRINTF (2, 0);
 GOErrorInfo *go_error_info_new_str_with_details	(char const *msg, GOErrorInfo *details);
 GOErrorInfo *go_error_info_new_str_with_details_list (char const *msg, GSList *details);
 GOErrorInfo *go_error_info_new_from_error_list	(GSList *errors);
