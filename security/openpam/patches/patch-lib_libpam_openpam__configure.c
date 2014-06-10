$NetBSD: patch-lib_libpam_openpam__configure.c,v 1.1 2014/06/10 13:17:42 joerg Exp $

--- lib/libpam/openpam_configure.c.orig	2013-09-07 13:28:00.000000000 +0000
+++ lib/libpam/openpam_configure.c
@@ -1,6 +1,6 @@
 /*-
  * Copyright (c) 2001-2003 Networks Associates Technology, Inc.
- * Copyright (c) 2004-2012 Dag-Erling Smørgrav
+ * Copyright (c) 2004-2014 Dag-Erling Smørgrav
  * All rights reserved.
  *
  * This software was developed for the FreeBSD Project by ThinkSec AS and
@@ -193,6 +193,7 @@ openpam_parse_chain(pam_handle_t *pamh,
 			openpam_log(PAM_LOG_ERROR,
 			    "%s(%d): missing or invalid facility",
 			    filename, lineno);
+			errno = EINVAL;
 			goto fail;
 		}
 		if (facility != fclt && facility != PAM_FACILITY_ANY) {
@@ -208,18 +209,28 @@ openpam_parse_chain(pam_handle_t *pamh,
 				openpam_log(PAM_LOG_ERROR,
 				    "%s(%d): missing or invalid service name",
 				    filename, lineno);
+				errno = EINVAL;
 				goto fail;
 			}
 			if (wordv[i] != NULL) {
 				openpam_log(PAM_LOG_ERROR,
 				    "%s(%d): garbage at end of line",
 				    filename, lineno);
+				errno = EINVAL;
 				goto fail;
 			}
 			ret = openpam_load_chain(pamh, servicename, fclt);
 			FREEV(wordc, wordv);
-			if (ret < 0)
+			if (ret < 0) {
+				/*
+				 * Bogus errno, but this ensures that the
+				 * outer loop does not just ignore the
+				 * error and keep searching.
+				 */
+				if (errno == ENOENT)
+					errno = EINVAL;
 				goto fail;
+			}
 			continue;
 		}
 
@@ -229,6 +240,7 @@ openpam_parse_chain(pam_handle_t *pamh,
 			openpam_log(PAM_LOG_ERROR,
 			    "%s(%d): missing or invalid control flag",
 			    filename, lineno);
+			errno = EINVAL;
 			goto fail;
 		}
 
@@ -238,6 +250,7 @@ openpam_parse_chain(pam_handle_t *pamh,
 			openpam_log(PAM_LOG_ERROR,
 			    "%s(%d): missing or invalid module name",
 			    filename, lineno);
+			errno = EINVAL;
 			goto fail;
 		}
 
@@ -247,8 +260,11 @@ openpam_parse_chain(pam_handle_t *pamh,
 		this->flag = ctlf;
 
 		/* load module */
-		if ((this->module = openpam_load_module(modulename)) == NULL)
+		if ((this->module = openpam_load_module(modulename)) == NULL) {
+			if (errno == ENOENT)
+				errno = ENOEXEC;
 			goto fail;
+		}
 
 		/*
 		 * The remaining items in wordv are the module's
@@ -281,7 +297,11 @@ openpam_parse_chain(pam_handle_t *pamh,
 	 * The loop ended because openpam_readword() returned NULL, which
 	 * can happen for four different reasons: an I/O error (ferror(f)
 	 * is true), a memory allocation failure (ferror(f) is false,
-	 * errno is non-zero)
+	 * feof(f) is false, errno is non-zero), the file ended with an
+	 * unterminated quote or backslash escape (ferror(f) is false,
+	 * feof(f) is true, errno is non-zero), or the end of the file was
+	 * reached without error (ferror(f) is false, feof(f) is true,
+	 * errno is zero).
 	 */
 	if (ferror(f) || errno != 0)
 		goto syserr;
@@ -402,6 +422,9 @@ openpam_load_chain(pam_handle_t *pamh,
 		}
 		ret = openpam_load_file(pamh, service, facility,
 		    filename, style);
+		/* success */
+		if (ret > 0)
+			RETURNN(ret);
 		/* the file exists, but an error occurred */
 		if (ret == -1 && errno != ENOENT)
 			RETURNN(ret);
@@ -411,7 +434,8 @@ openpam_load_chain(pam_handle_t *pamh,
 	}
 
 	/* no hit */
-	RETURNN(0);
+	errno = ENOENT;
+	RETURNN(-1);
 }
 
 /*
@@ -432,8 +456,10 @@ openpam_configure(pam_handle_t *pamh,
 		openpam_log(PAM_LOG_ERROR, "invalid service name");
 		RETURNC(PAM_SYSTEM_ERR);
 	}
-	if (openpam_load_chain(pamh, service, PAM_FACILITY_ANY) < 0)
-		goto load_err;
+	if (openpam_load_chain(pamh, service, PAM_FACILITY_ANY) < 0) {
+		if (errno != ENOENT)
+			goto load_err;
+	}
 	for (fclt = 0; fclt < PAM_NUM_FACILITIES; ++fclt) {
 		if (pamh->chains[fclt] != NULL)
 			continue;
