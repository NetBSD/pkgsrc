$NetBSD: patch-erts_emulator_sys_common_erl__poll.c,v 1.3 2018/09/18 04:12:04 maya Exp $

ERL-725: ports fail to send exit_status on NetBSD
https://bugs.erlang.org/browse/ERL-725

--- erts/emulator/sys/common/erl_poll.c.orig	2018-09-11 14:57:05.000000000 +0000
+++ erts/emulator/sys/common/erl_poll.c
@@ -820,7 +820,7 @@ update_pollset(ErtsPollSet *ps, int fd, 
         }
     }
 
-#if defined(EV_DISPATCH) && !defined(__OpenBSD__)
+#if defined(EV_DISPATCH) && !(defined(__OpenBSD__) || defined(__NetBSD__))
     /* If we have EV_DISPATCH we use it, unless we are on OpenBSD as the
        behavior of EV_EOF seems to be edge triggered there and we need it
        to be level triggered.
