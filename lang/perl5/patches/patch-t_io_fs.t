$NetBSD: patch-t_io_fs.t,v 1.1 2019/04/23 09:27:46 adam Exp $

On NetBSD, filesystems may be mounted with the noatime option.

--- t/io/fs.t.orig	2013-05-01 02:52:56.000000000 +0000
+++ t/io/fs.t
@@ -275,15 +275,15 @@ sub check_utime_result {
 		is( $atime, 500000001,          'atime' );
 		is( $mtime, 500000000 + $delta, 'mtime' );
 	    }
-	    elsif ($^O eq 'haiku') {
+	    elsif ($^O eq 'haiku' || $^O eq 'netbsd') {
             SKIP: {
 		    skip "atime not updated", 1;
 		}
 		is($mtime, 500000001, 'mtime');
 	    }
 	    else {
-		fail("atime");
-		fail("mtime");
+		fail("atime: expected 500000000, got ${atime}");
+		fail("mtime: expected ".(500000000+$delta).", got ${mtime}");
 	    }
 	}
     }
