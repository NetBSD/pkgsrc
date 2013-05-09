$NetBSD: patch-pdns_dnspacket.cc,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- pdns/dnspacket.cc.orig	2013-05-09 15:25:33.000000000 +0000
+++ pdns/dnspacket.cc
@@ -335,7 +335,7 @@ void DNSPacket::wrapup(void)
 	}
 	if(pos->content.empty())  // empty contents confuse the MOADNS setup
 	  pos->content=".";
-	shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(pos->qtype.getCode(), 1, pos->content)); 
+	boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(pos->qtype.getCode(), 1, pos->content)); 
 	drc->toPacket(pw);
       }
       if(!opts.empty())
