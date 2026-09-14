$NetBSD: patch-tests_test__echo__tcp__get__peer__sock__name.c,v 1.1 2026/09/14 22:10:50 wiz Exp $

_assert_in_range not found, use different, existing one that checks the same.

--- tests/test_echo_tcp_get_peer_sock_name.c.orig	2024-06-10 07:43:42.000000000 +0000
+++ tests/test_echo_tcp_get_peer_sock_name.c
@@ -112,11 +112,9 @@ static void _assert_sockaddr_port_range_equal(struct t
 		return;
 	}
 
-	_assert_in_range(ntohs(n_port),
+	assert_int_in_range(ntohs(n_port),
 			 min_port,
-			 max_port,
-			 file,
-			 line);
+			 max_port);
 }
 
 #define assert_sockaddr_port_range_equal(ss, a, min_prt, max_prt) \
