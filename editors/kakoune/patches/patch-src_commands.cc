$NetBSD: patch-src_commands.cc,v 1.1 2020/05/14 19:06:55 joerg Exp $

--- src/commands.cc.orig	2020-05-11 00:38:19.003563913 +0000
+++ src/commands.cc
@@ -1962,7 +1962,7 @@ const CommandDesc eval_string_cmd = {
             ScopedSetBool disable_hoooks(context.hooks_disabled(), no_hooks);
 
             if (parser.get_switch("verbatim"))
-                CommandManager::instance().execute_single_command(parser | gather<Vector>(), context, shell_context);
+                CommandManager::instance().execute_single_command(parser | gather<Vector<String>>(), context, shell_context);
             else
                 CommandManager::instance().execute(join(parser, ' ', false), context, shell_context);
         });
