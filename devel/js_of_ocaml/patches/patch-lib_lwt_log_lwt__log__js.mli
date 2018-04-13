$NetBSD: patch-lib_lwt_log_lwt__log__js.mli,v 1.1 2018/04/13 12:59:41 jaapb Exp $

Use Lwt_log_core instead of Lwt_log (threading not needed)
--- lib/lwt/log/lwt_log_js.mli.orig	2018-02-21 22:12:58.000000000 +0000
+++ lib/lwt/log/lwt_log_js.mli
@@ -29,7 +29,7 @@ include module type of Lwt_log_core
 
 (** {2 Predefined logger} *)
 
-val console : Lwt_log.logger
+val console : Lwt_log_core.logger
 (** Logger that use the javascript console object. *)
 
 
