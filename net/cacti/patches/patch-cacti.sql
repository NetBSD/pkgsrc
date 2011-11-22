$NetBSD: patch-cacti.sql,v 1.1.1.1 2011/11/22 22:23:13 tez Exp $

use a generic scriptname rather than an OS specific one

--- cacti.sql.orig	2011-09-26 20:41:03.000000000 +0000
+++ cacti.sql
@@ -195,7 +195,7 @@ INSERT INTO data_input VALUES (2,'bf566c
 INSERT INTO data_input VALUES (3,'274f4685461170b9eb1b98d22567ab5e','Unix - Get Free Disk Space','<path_cacti>/scripts/diskfree.sh <partition>',1);
 INSERT INTO data_input VALUES (4,'95ed0993eb3095f9920d431ac80f4231','Unix - Get Load Average','perl <path_cacti>/scripts/loadavg_multi.pl',1);
 INSERT INTO data_input VALUES (5,'79a284e136bb6b061c6f96ec219ac448','Unix - Get Logged In Users','perl <path_cacti>/scripts/unix_users.pl <username>',1);
-INSERT INTO data_input VALUES (6,'362e6d4768937c4f899dd21b91ef0ff8','Linux - Get Memory Usage','perl <path_cacti>/scripts/linux_memory.pl <grepstr>',1);
+INSERT INTO data_input VALUES (6,'362e6d4768937c4f899dd21b91ef0ff8','Linux - Get Memory Usage','perl <path_cacti>/scripts/local_memory.pl <grepstr>',1);
 INSERT INTO data_input VALUES (7,'a637359e0a4287ba43048a5fdf202066','Unix - Get System Processes','perl <path_cacti>/scripts/unix_processes.pl',1);
 INSERT INTO data_input VALUES (8,'47d6bfe8be57a45171afd678920bd399','Unix - Get TCP Connections','perl <path_cacti>/scripts/unix_tcp_connections.pl <grepstr>',1);
 INSERT INTO data_input VALUES (9,'cc948e4de13f32b6aea45abaadd287a3','Unix - Get Web Hits','perl <path_cacti>/scripts/webhits.pl <log_path>',1);
