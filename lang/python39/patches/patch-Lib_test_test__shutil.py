$NetBSD: patch-Lib_test_test__shutil.py,v 1.1 2023/11/10 09:48:40 nia Exp $

posix.copyfile does not exist on Tiger. 

Python 3.8's posix._fcopyfile implementation unconditionally uses <copyfile.h>, 
which only exists on Leopard ane newer. This patch removes posix._fcopyfile 
on Tiger - this is okay because the rest of the stdlib uses posix._fcopyfile 
only conditionally after checking that the function exists 
(non-Apple systems don't have posix._fcopyfile either).


thanks to @dgelessus
https://github.com/macports/macports-ports/pull/5987

--- Lib/test/test_shutil.py.orig	2023-08-24 17:59:28.000000000 +0000
+++ Lib/test/test_shutil.py
@@ -2569,7 +2569,7 @@ class TestZeroCopySendfile(_ZeroCopyFile
             shutil._USE_CP_SENDFILE = True
 
 
-@unittest.skipIf(not MACOS, 'macOS only')
+@unittest.skipIf(not MACOS or not hasattr(posix, "_fcopyfile"), 'macOS with posix._fcopyfile only')
 class TestZeroCopyMACOS(_ZeroCopyFileTest, unittest.TestCase):
     PATCHPOINT = "posix._fcopyfile"
 
