$NetBSD: mailnews_extensions_enigmail_ipc_modules_subprocess.jsm,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mailnews/extensions/enigmail/ipc/modules/subprocess.jsm.orig	2012-02-09 16:50:47.000000000 +0000
+++ mailnews/extensions/enigmail/ipc/modules/subprocess.jsm
@@ -312,7 +312,9 @@ function getPlatformValue(valueType) {
         //            library name   O_NONBLOCK RLIM_T                RLIMIT_NOFILE
         'darwin':  [ 'libc.dylib',   0x04     , ctypes.uint64_t     , 8 ],
         'linux':   [ 'libc.so.6',    2024     , ctypes.unsigned_long, 7 ],
+        'dragonfly': [ 'libc.so',    0x04     , ctypes.int64_t      , 8 ],
         'freebsd': [ 'libc.so.7',    0x04     , ctypes.int64_t      , 8 ],
+        'netbsd': [ 'libc.so', 0x04     , ctypes.int64_t      , 8 ],
         'openbsd': [ 'libc.so.61.0', 0x04     , ctypes.int64_t      , 8 ],
         'sunos':   [ 'libc.so',      0x80     , ctypes.unsigned_long, 5 ]
     }
