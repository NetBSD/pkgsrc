$NetBSD: patch-vendor_github.com_docker_docker_pkg_system_stat__netbsd.go,v 1.1 2020/09/10 22:10:59 he Exp $

Provide fromStatT for NetBSD.

--- /dev/null	2020-09-10 16:25:00.659600321 +0200
+++ vendor/github.com/docker/docker/pkg/system/stat_netbsd.go	2020-09-10 16:25:03.639679600 +0200
@@ -0,0 +1,13 @@
+package system // import "github.com/docker/docker/pkg/system"
+
+import "syscall"
+
+// fromStatT converts a syscall.Stat_t type to a system.Stat_t type
+func fromStatT(s *syscall.Stat_t) (*StatT, error) {
+	return &StatT{size: s.Size,
+		mode: uint32(s.Mode),
+		uid:  s.Uid,
+		gid:  s.Gid,
+		rdev: uint64(s.Rdev),
+		mtim: s.Mtimespec}, nil
+}
