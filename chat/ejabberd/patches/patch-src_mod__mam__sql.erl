$NetBSD: patch-src_mod__mam__sql.erl,v 1.1 2026/08/06 12:09:43 gdt Exp $

Building fails with NS_MAM_FULLTEXT_0 undefined, but I can't find
where any such defines are.  Because I don't use mysql and nobody else
has said they do, just omit it, leaving a proper fix to someone who
does, or upstream fixing this.

Not reported upstream until we are caught up, at least.

--- src/mod_mam_sql.erl.orig	2026-04-14 14:15:06.000000000 +0000
+++ src/mod_mam_sql.erl
@@ -287,7 +287,7 @@ delete_old_messages(ServerHost, TimeStam
 additional_namespaces(LServer) ->
     case ejabberd_option:sql_type(LServer) of
 	mysql ->
-	    [?NS_MAM_FULLTEXT_0];
+	    [];
 	_ ->
 	    []
     end.
