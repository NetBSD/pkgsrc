$NetBSD: patch-paexec_paexec.c,v 1.1 2013/03/08 14:06:30 cheusov Exp $

-t '' is equivalent to "no transport"
--- paexec/paexec.c.orig	2013-03-07 12:24:17.000000000 +0000
+++ paexec/paexec.c
@@ -955,7 +955,8 @@ static void process_args (int *argc, cha
 				arg_cmd = xstrdup (optarg);
 				break;
 			case 't':
-				arg_transport = xstrdup (optarg);
+				if (optarg [0])
+					arg_transport = xstrdup (optarg);
 				break;
 			case 'p':
 				show_pid = 1;
