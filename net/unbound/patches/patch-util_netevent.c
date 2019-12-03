$NetBSD: patch-util_netevent.c,v 1.1 2019/12/03 08:08:58 he Exp $

Apply fix from
  https://github.com/NLnetLabs/unbound/pull/122
which fixes
  https://github.com/NLnetLabs/unbound/issues/125

Briefly: TCP socket timeouts would effectively be disabled after
the exchange of the initial DNS query/response.

--- util/netevent.c.orig	2019-11-19 06:51:50.000000000 +0000
+++ util/netevent.c
@@ -1001,7 +1001,7 @@ tcp_callback_writer(struct comm_point* c
 		tcp_req_info_handle_writedone(c->tcp_req_info);
 	} else {
 		comm_point_stop_listening(c);
-		comm_point_start_listening(c, -1, -1);
+		comm_point_start_listening(c, -1, c->tcp_timeout_msec);
 	}
 }
 
