$NetBSD: patch-gif2png.go,v 1.1 2019/11/15 09:05:56 wiz Exp $

Fix on NetBSD.
https://gitlab.com/esr/gif2png/merge_requests/3

--- gif2png.go.orig	2019-07-11 13:50:28.000000000 +0000
+++ gif2png.go
@@ -98,7 +98,7 @@ func processfilter() int {
 
 func processfile(name string, fp *os.File) int {
 	var suppressDelete int
-	var timeBuf unix.Utimbuf
+	var timeBuf []unix.Timespec
 
 	if fp == nil {
 		return 1
@@ -118,8 +118,12 @@ func processfile(name string, fp *os.Fil
 
 		// Ugh...Go doesn't have a way to retrieve access time.
 		// So we'll duplicare the mod time, alas.
-		timeBuf.Actime  = fi.ModTime().Unix()
-		timeBuf.Modtime = fi.ModTime().Unix()
+		ts, err := unix.TimeToTimespec(fi.ModTime())
+		if err != nil {
+			return 1
+		}
+		timeBuf = append(timeBuf, ts)
+		timeBuf = append(timeBuf, ts)
 	}
 
 	fp.Close()
@@ -170,7 +174,7 @@ func processfile(name string, fp *os.Fil
 		fp.Close()
 
 		if preserveMtime {
-			err =  unix.Utime(outname, &timeBuf)
+			err =  unix.UtimesNano(outname, timeBuf)
 			if err != nil {
 				fmt.Fprintf(os.Stderr, "gifpng: could not set output file times\n");
 				return 1;
