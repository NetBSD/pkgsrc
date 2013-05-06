$NetBSD: patch-sql_rpl__slave.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/rpl_slave.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/rpl_slave.cc
@@ -3492,7 +3492,7 @@ apply_event_and_update_pos(Log_event** p
         "skipped because event skip counter was non-zero"
       };
       DBUG_PRINT("info", ("OPTION_BEGIN: %d; IN_STMT: %d",
-                          test(thd->variables.option_bits & OPTION_BEGIN),
+                          my_test(thd->variables.option_bits & OPTION_BEGIN),
                           rli->get_flag(Relay_log_info::IN_STMT)));
       DBUG_PRINT("skip_event", ("%s event was %s",
                                 ev->get_type_str(), explain[reason]));
