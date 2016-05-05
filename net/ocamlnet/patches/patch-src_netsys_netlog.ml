$NetBSD: patch-src_netsys_netlog.ml,v 1.1 2016/05/05 16:04:21 jaapb Exp $

Temporary patch for ocaml 4.03 (from package's git repository)
--- src/netsys/netlog.ml.orig	2016-02-29 12:24:18.000000000 +0000
+++ src/netsys/netlog.ml
@@ -8,6 +8,15 @@ type level =
 type logger =
     level -> string -> unit
 
+type timespec = float * int
+type clock_id
+type clock =
+  | CLOCK_REALTIME
+  | CLOCK_MONOTONIC
+  | CLOCK_ID of clock_id
+
+external clock_gettime : clock -> timespec = "netsys_clock_gettime"
+
 let level_weight =
   function
     | `Emerg   -> 0
@@ -95,7 +104,7 @@ let current_formatter =
 let channel_logger ch max_lev lev msg = 
   if level_weight lev <= level_weight max_lev then (
     let (sec,ns) =
-      try Netsys_posix.clock_gettime Netsys_posix.CLOCK_REALTIME
+      try clock_gettime CLOCK_REALTIME
       with Invalid_argument _ ->
 	(Unix.gettimeofday(), 0) in
     let s =   (* Netdate is unavailable here *)
