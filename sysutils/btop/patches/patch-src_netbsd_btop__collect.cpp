$NetBSD: patch-src_netbsd_btop__collect.cpp,v 1.3 2026/09/24 09:43:26 wiz Exp $

https://github.com/aristocratos/btop/pull/1852

--- src/netbsd/btop_collect.cpp.orig	2026-05-01 16:05:43.000000000 +0000
+++ src/netbsd/btop_collect.cpp
@@ -627,8 +627,6 @@ namespace Mem {
 
 namespace Mem {
 	bool has_swap = false;
-	vector<string> fstab;
-	fs::file_time_type fstab_time;
 	int disk_ios = 0;
 	vector<string> last_found;
 
@@ -756,7 +754,7 @@ namespace Mem {
 			double uptime = system_uptime();
 			auto &disks_filter = Config::getS("disks_filter");
 			bool filter_exclude = false;
-			// auto only_physical = Config::getB("only_physical");
+			auto only_physical = Config::getB("only_physical");
 			auto &disks = mem.disks;
 			vector<string> filter;
 			if (not disks_filter.empty()) {
@@ -773,15 +771,14 @@ namespace Mem {
 			found.reserve(last_found.size());
 			for (int i = 0; i < count; i++) {
 				auto fstype = string(stvfs[i].f_fstypename);
-				if (fstype == "autofs" || fstype == "devfs" || fstype == "linprocfs" || fstype == "procfs" || fstype == "tmpfs" || fstype == "linsysfs" ||
-					fstype == "fdesckfs") {
-					// in memory filesystems -> not useful to show
+				string dev = stvfs[i].f_mntfromname;
+				//? Physical = backed by a block device (source under /dev/, or the kernel's root_device placeholder before rc.d/root remounts /) or ZFS (source is pool[/dataset]).
+				//? Pseudo (kernfs, ptyfs, tmpfs, procfs, ...) and network (host:/path) filesystems have other sources.
+				if (only_physical and not dev.starts_with("/dev/") and dev != "root_device" and fstype != "zfs")
 					continue;
-				}
 
 				std::error_code ec;
 				string mountpoint = stvfs[i].f_mntonname;
-				string dev = stvfs[i].f_mntfromname;
 				mapping[dev] = mountpoint;
 
 				//? Match filter if not empty
