$NetBSD: patch-ecs-cli_vendor_github.com_docker_docker_pkg_system_stat__netbsd.go,v 1.1 2020/09/12 14:53:39 leot Exp $

Add support for NetBSD.

Shared upstream via:

 <https://github.com/moby/moby/pull/41441>

--- /dev/null	2020-09-01 18:37:14.499473640 +0000
+++ ecs-cli/vendor/github.com/docker/docker/pkg/system/stat_netbsd.go
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
