$NetBSD: patch-misc.hh,v 1.1.2.2 2020/06/25 18:21:29 bsiegert Exp $

backport changes based on PR #9127 from
https://github.com/PowerDNS/pdns/pull/9127

--- misc.hh.orig	2020-05-08 09:31:59.000000000 +0000
+++ misc.hh
@@ -607,3 +607,5 @@ bool isSettingThreadCPUAffinitySupported
 int mapThreadToCPUList(pthread_t tid, const std::set<int>& cpus);
 
 std::vector<ComboAddress> getResolvers(const std::string& resolvConfPath);
+
+std::string getCarbonHostName();
