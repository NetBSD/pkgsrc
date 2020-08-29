$NetBSD: patch-parse.y,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- parse.y.orig	2019-02-12 22:08:26.000000000 +0000
+++ parse.y
@@ -206,6 +206,7 @@ yyerror(const char *fmt, ...)
 %token TOKNOT
 %token TOKNOUIDL
 %token TOKNOVERIFY
+%token TOKOAUTHBEARER
 %token TOKOLDONLY
 %token TOKOR
 %token TOKPARALLELACCOUNTS
@@ -307,7 +308,7 @@ yyerror(const char *fmt, ...)
 %type  <fetch> fetchtype
 %type  <flag> cont not disabled keep execpipe writeappend compress verify
 %type  <flag> apop poptype imaptype nntptype nocrammd5 nologin uidl starttls
-%type  <flag> insecure
+%type  <flag> insecure oauthbearer
 %type  <localgid> localgid
 %type  <locks> lock locklist
 %type  <number> size time numv retrc expire
@@ -1211,7 +1212,7 @@ actitem: execpipe strv
 		 data->compress = $3;
 	 }
        | imaptype server userpassnetrc folder1 verify nocrammd5 nologin
-	 starttls insecure
+	 starttls insecure oauthbearer
 	 {
 		 struct deliver_imap_data	*data;
 
@@ -1252,6 +1253,7 @@ actitem: execpipe strv
 		 data->nologin = $7;
 		 data->starttls = $8;
 		 data->server.insecure = $9;
+		 data->oauthbearer = $10;
 	 }
        | TOKSMTP server from to
 	 {
@@ -2051,6 +2053,15 @@ insecure: TOKINSECURE
 		$$ = 0;
 	}
 
+oauthbearer: TOKOAUTHBEARER
+	   {
+		   $$ = 1;
+	   }
+	 | /* empty */
+	   {
+		   $$ = 0;
+	   }
+
 verify: TOKNOVERIFY
 	{
 		$$ = 0;
@@ -2253,7 +2264,7 @@ fetchtype: poptype server userpassnetrc 
 		   data->only = $5.only;
 	   }
 	 | imaptype server userpassnetrc folderlist imaponly verify nocrammd5
-	   nologin starttls insecure
+	   nologin starttls insecure oauthbearer
 	   {
 		   struct fetch_imap_data	*data;
 
@@ -2293,6 +2304,7 @@ fetchtype: poptype server userpassnetrc 
 		   data->nologin = $8;
 		   data->starttls = $9;
 		   data->server.insecure = $10;
+		   data->oauthbearer = $11;
 	   }
 	 | TOKIMAP TOKPIPE replstrv userpass folderlist imaponly
 	   {
