$NetBSD: patch-pdns_dnspbench.cc,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- pdns/dnspbench.cc.orig	2013-05-09 15:25:39.000000000 +0000
+++ pdns/dnspbench.cc
@@ -85,7 +85,7 @@ try
   cerr<<"hexdump: "<<makeHexDump(record)<<"\n";
   //  cerr<<"record: "<<record<<"\n";
 
-  shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(argv[1], type, record);
+  boost::shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(argv[1], type, record);
   cerr<<"Out: "<<argv[1]<<" IN "<<argv[2]<<" "<<regen->getZoneRepresentation()<<endl;
 #endif
 }
