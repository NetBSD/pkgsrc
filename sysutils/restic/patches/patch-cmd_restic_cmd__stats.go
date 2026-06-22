$NetBSD: patch-cmd_restic_cmd__stats.go,v 1.1 2026/06/22 22:09:45 wiz Exp $

stats: hide progress bar for json output
https://github.com/restic/restic/pull/21871

--- cmd/restic/cmd_stats.go.orig	2026-06-09 16:49:04.000000000 +0000
+++ cmd/restic/cmd_stats.go
@@ -141,7 +141,7 @@ func runStats(ctx context.Context, opts StatsOptions, 
 		snapshots = append(snapshots, sn)
 	}
 
-	statsProgress := newStatsProgress(term, uint64(len(snapshots)))
+	statsProgress := newStatsProgress(term, !gopts.JSON, uint64(len(snapshots)))
 
 	updater := progress.NewUpdater(ui.CalculateProgressInterval(!gopts.Quiet, gopts.JSON, term.CanUpdateStatus()), func(runtime time.Duration, final bool) {
 		statsProgress.printProgress(runtime, final)
@@ -375,6 +375,7 @@ type statsProgress struct {
 	term          ui.Terminal
 	m             sync.Mutex
 	snapshotCount uint64
+	show          bool
 
 	processedSnapshotCount uint64
 	processedFileCount     uint64
@@ -382,14 +383,18 @@ type statsProgress struct {
 	processedSize          uint64
 }
 
-func newStatsProgress(term ui.Terminal, snapshotCount uint64) *statsProgress {
+func newStatsProgress(term ui.Terminal, show bool, snapshotCount uint64) *statsProgress {
 	return &statsProgress{
 		term:          term,
+		show:          show,
 		snapshotCount: snapshotCount,
 	}
 }
 
 func (s *statsProgress) printProgress(runtime time.Duration, final bool) {
+	if !s.show {
+		return
+	}
 	s.m.Lock()
 
 	progressBase := s.processedSnapshotCount
