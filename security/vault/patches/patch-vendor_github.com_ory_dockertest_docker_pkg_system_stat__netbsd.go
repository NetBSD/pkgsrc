$NetBSD: patch-vendor_github.com_ory_dockertest_docker_pkg_system_stat__netbsd.go,v 1.1 2019/10/23 15:00:05 he Exp $

Create stat_netbsd.go file so that fromStatT is defined.

--- /dev/null	2019-10-22 10:44:39.662720199 +0200
+++ vendor/github.com/ory/dockertest/docker/pkg/system/stat_netbsd.go	2019-10-22 10:51:32.742089646 +0200
@@ -0,0 +1,13 @@
+package system // import "github.com/ory/dockertest/docker/pkg/system"
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
