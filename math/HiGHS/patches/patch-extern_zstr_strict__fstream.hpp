$NetBSD: patch-extern_zstr_strict__fstream.hpp,v 1.1 2026/10/17 20:45:04 alnsn Exp $

NetBSD has the XSI-compliant strerror_r().

--- extern/zstr/strict_fstream.hpp.orig	2026-10-17 00:31:20.154535413 +0000
+++ extern/zstr/strict_fstream.hpp
@@ -64,7 +64,7 @@ static std::string strerror()
     } else {
         return "Unknown error (" + std::to_string(err_num) + ")";
     }
-#elif ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600 || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)) && ! _GNU_SOURCE) || defined(__MUSL__)
+#elif ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600 || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)) && ! _GNU_SOURCE) || defined(__MUSL__) || defined(__NetBSD__)
 // XSI-compliant strerror_r()
     const int err_num = errno; // See above
     if (strerror_r(err_num, buff.data(), buff.size()) == 0) {
