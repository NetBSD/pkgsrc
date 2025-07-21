$NetBSD: patch-yazi-core_src_mgr_watcher.rs,v 1.1 2025/07/21 22:00:56 wiz Exp $

https://github.com/sxyazi/yazi/pull/2941

--- yazi-core/src/mgr/watcher.rs.orig	2025-05-30 16:39:47.000000000 +0000
+++ yazi-core/src/mgr/watcher.rs
@@ -36,7 +36,7 @@ impl Watcher {
 		};
 
 		let config = notify::Config::default().with_poll_interval(Duration::from_millis(500));
-		if yazi_adapter::WSL.get() {
+		if yazi_adapter::WSL.get() || cfg!(target_os = "netbsd") {
 			tokio::spawn(Self::fan_in(in_rx, PollWatcher::new(handler, config).unwrap()));
 		} else {
 			tokio::spawn(Self::fan_in(in_rx, RecommendedWatcher::new(handler, config).unwrap()));
