$NetBSD: patch-tests_dtls_dtls-stress.c,v 1.1 2026/11/19 03:22:19 wiz Exp $

  CC       dtls/dtls-stress.o
dtls/dtls-stress.c:681:25: error: initialization of 'timer_t' {aka 'int'} from 'void *' makes integer from pointer without a cast [-Wint-conversion]
  681 | timer_t killtimer_tid = NULL;
      |                         ^~~~
dtls/dtls-stress.c: In function 'killtimer_set':
dtls/dtls-stress.c:688:27: warning: comparison between pointer and integer
  688 |         if (killtimer_tid != NULL) {
      |                           ^~

https://gitlab.com/gnutls/gnutls/-/work_items/2027

--- tests/dtls/dtls-stress.c.orig	2026-11-19 02:57:13.229500765 +0000
+++ tests/dtls/dtls-stress.c
@@ -678,14 +678,14 @@ DECLARE_PERMUTE(ClientFinishedFull)
 DECLARE_PERMUTE(ClientFinishedFull)
 // }}}
 // {{{ emergency deadlock resolution time bomb
-timer_t killtimer_tid = NULL;
+timer_t killtimer_tid = 0;
 
 static void killtimer_set(void)
 {
 	struct sigevent sig;
 	struct itimerspec tout = { { 0, 0 }, { 2 * timeout_seconds, 0 } };
 
-	if (killtimer_tid != NULL) {
+	if (killtimer_tid != 0) {
 		timer_delete(killtimer_tid);
 	}
 
