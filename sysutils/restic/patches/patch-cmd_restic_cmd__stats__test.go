$NetBSD: patch-cmd_restic_cmd__stats__test.go,v 1.1 2026/06/22 22:09:45 wiz Exp $

stats: hide progress bar for json output
https://github.com/restic/restic/pull/21871

--- cmd/restic/cmd_stats_test.go.orig	2026-06-09 16:49:04.000000000 +0000
+++ cmd/restic/cmd_stats_test.go
@@ -66,7 +66,7 @@ func TestStatsProgress(t *testing.T) {
 func TestStatsProgress(t *testing.T) {
 	term := &ui.MockTerminal{}
 
-	progress := newStatsProgress(term, 2)
+	progress := newStatsProgress(term, true, 2)
 	progress.printProgress(0*time.Second, false)
 	rtest.Equals(t, []string{"[0:00] 0.00%  0 / 2 snapshots, 0 B"}, term.Output)
 
@@ -87,4 +87,13 @@ func TestStatsProgress(t *testing.T) {
 
 	progress.printProgress(20*time.Second, true)
 	rtest.Equals(t, []string{"[0:20] 100.00%  2 / 2 snapshots, 4 files, 5 blobs, 6 B"}, term.Output)
+}
+
+func TestStatsProgressJSON(t *testing.T) {
+	term := &ui.MockTerminal{}
+
+	progress := newStatsProgress(term, false, 2)
+	progress.printProgress(0*time.Second, false)
+	// JSON output is not available yet, so just make sure to not break normal json output
+	rtest.Equals(t, nil, term.Output)
 }
