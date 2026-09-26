$NetBSD: patch-collector_meminfo__netbsd.go,v 1.1 2026/09/26 13:53:56 tnn Exp $

Expose more of the vm.uvmexp2 sysctl as node_memory_* metrics.
TODO upstream this.

--- collector/meminfo_netbsd.go.orig	2026-07-14 12:03:47.000000000 +0000
+++ collector/meminfo_netbsd.go
@@ -43,8 +43,12 @@ func (c *meminfoCollector) getMemInfo() (map[string]fl
 	// see uvm(9)
 	return map[string]float64{
 		"active_bytes":                  ps * float64(uvmexp.Active),
+		"anon_bytes":                    ps * float64(uvmexp.Anonpages),
+		"exec_bytes":                    ps * float64(uvmexp.Execpages),
+		"file_bytes":                    ps * float64(uvmexp.Filepages),
 		"free_bytes":                    ps * float64(uvmexp.Free),
 		"inactive_bytes":                ps * float64(uvmexp.Inactive),
+		"pool_bytes":                    ps * float64(uvmexp.Poolpages),
 		"size_bytes":                    ps * float64(uvmexp.Npages),
 		"swap_size_bytes":               ps * float64(uvmexp.Swpages),
 		"swap_used_bytes":               ps * float64(uvmexp.Swpginuse),
