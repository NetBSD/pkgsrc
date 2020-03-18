$NetBSD: patch-source_src_master.cpp,v 1.1 2020/03/18 17:55:46 joerg Exp $

Truncate time_t to uint.

--- source/src/master.cpp.orig	2020-03-18 14:23:02.395419378 +0000
+++ source/src/master.cpp
@@ -510,7 +510,7 @@ void reqauth(client &c, uint id, char *n
     authreq &a = c.authreqs.add();
     a.reqtime = servtime;
     a.id = id;
-    uint seed[3] = { starttime, servtime, randomMT() };
+    uint seed[3] = { static_cast<uint>(starttime), servtime, randomMT() };
     static vector<char> buf;
     buf.setsize(0);
     a.answer = genchallenge(u->pubkey, seed, sizeof(seed), buf);
