$NetBSD: patch-lib_utils_mu-logger.cc,v 1.1 2024/05/02 13:35:48 ktnb Exp $

Only Linux has systemd

--- lib/utils/mu-logger.cc.orig	2024-05-01 14:55:55.224250331 +0000
+++ lib/utils/mu-logger.cc
@@ -156,8 +156,12 @@ Mu::Logger::Logger(const std::string& pa
 		    }
 
 		    // log to the journal, or, if not available to a file.
+#if defined(__linux__)
 		    if (any_of(MuLogOptions & Options::File) ||
 			log_journal(level, fields, n_fields, user_data) != G_LOG_WRITER_HANDLED)
+#else
+		    if (any_of(MuLogOptions & Options::File))
+#endif
 			    return log_file(level, fields, n_fields, user_data);
 		    else
 			    return G_LOG_WRITER_HANDLED;
