$NetBSD: patch-sql_net__serv.cc,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- sql/net_serv.cc.orig	2013-04-28 13:54:10.000000000 +0000
+++ sql/net_serv.cc
@@ -316,7 +316,7 @@ my_bool my_net_write(NET *net, const uch
 #ifndef DEBUG_DATA_PACKETS
   DBUG_DUMP("packet_header", buff, NET_HEADER_SIZE);
 #endif
-  rc= test(net_write_buff(net,packet,len));
+  rc= my_test(net_write_buff(net,packet,len));
   MYSQL_NET_WRITE_DONE(rc);
   return rc;
 }
@@ -390,7 +390,7 @@ net_write_command(NET *net,uchar command
   }
   int3store(buff,length);
   buff[3]= (uchar) net->pkt_nr++;
-  rc= test(net_write_buff(net, buff, header_size) ||
+  rc= my_test(net_write_buff(net, buff, header_size) ||
            (head_len && net_write_buff(net, header, head_len)) ||
            net_write_buff(net, packet, len) || net_flush(net));
   MYSQL_NET_WRITE_DONE(rc);
@@ -525,7 +525,7 @@ net_write_raw_loop(NET *net, const uchar
 #endif
   }
 
-  return test(count);
+  return my_test(count);
 }
 
 
@@ -700,7 +700,7 @@ static my_bool net_read_raw_loop(NET *ne
 #endif
   }
 
-  return test(count);
+  return my_test(count);
 }
 
 
