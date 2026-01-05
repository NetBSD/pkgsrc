$NetBSD: patch-hw_9pfs_9p-util.h,v 1.2 2026/01/05 10:11:38 adam Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/9p-util.h.orig	2025-12-23 19:48:56.000000000 +0000
+++ hw/9pfs/9p-util.h
@@ -93,6 +93,298 @@ static inline int errno_to_dotl(int err)
     } else if (err == EOPNOTSUPP) {
         err = 95; /* ==EOPNOTSUPP on Linux */
     }
+#elif defined(CONFIG_BSD)
+    switch (err) {
+        /* linux uapi/asm-generic/errno-base.h */
+    case EPERM:
+        return 1;
+    case ENOENT:
+        return 2;
+    case ESRCH:
+        return 3;
+    case EINTR:
+        return 4;
+    case EIO:
+        return 5;
+    case ENXIO:
+        return 6;
+    case E2BIG:
+        return 7;
+    case ENOEXEC:
+        return 8;
+    case EBADF:
+        return 9;
+    case ECHILD:
+        return 10;
+    case EAGAIN:
+        return 11;
+    case ENOMEM:
+        return 12;
+    case EACCES:
+        return 13;
+    case EFAULT:
+        return 14;
+    case ENOTBLK:
+        return 15;
+    case EBUSY:
+        return 16;
+    case EEXIST:
+        return 17;
+    case EXDEV:
+        return 18;
+    case ENODEV:
+        return 19;
+    case ENOTDIR:
+        return 20;
+    case EISDIR:
+        return 21;
+    case EINVAL:
+        return 22;
+    case ENFILE:
+        return 23;
+    case EMFILE:
+        return 24;
+    case ENOTTY:
+        return 25;
+    case ETXTBSY:
+        return 26;
+    case EFBIG:
+        return 27;
+    case ENOSPC:
+        return 28;
+    case ESPIPE:
+        return 29;
+    case EROFS:
+        return 30;
+    case EMLINK:
+        return 31;
+    case EPIPE:
+        return 32;
+    case EDOM:
+        return 33;
+    case ERANGE:
+        return 34;
+        /* linux uapi/asm-generic/errno.h */
+    case EDEADLK:
+        return 35;
+    case ENAMETOOLONG:
+        return 36;
+    case ENOLCK:
+        return 37;
+    case ENOSYS:
+        return 38;
+    case ENOTEMPTY:
+        return 39;
+    case ELOOP:
+        return 40;
+    case ENOMSG:
+        return 41;
+    case EIDRM:
+        return 43;
+# if 0
+    case ECHRNG:
+        return 44;
+    case EL2NSYNC:
+        return 45;
+    case EL3HLT:
+        return 46;
+    case EL3RST:
+        return 47;
+    case ELNRNG:
+        return 48;
+    case EUNATCH:
+        return 49;
+    case ENOCSI:
+        return 50;
+    case EL2HLT:
+        return 51;
+    case EBADE:
+        return 52;
+    case EBADR:
+        return 53;
+    case EXFULL:
+        return 54;
+    case ENOANO:
+        return 55;
+    case EBADRQC:
+        return 56;
+    case EBADSLT:
+        return 57;
+    case EBFONT:
+        return 58;
+# endif
+    case ENOSTR:
+        return 60;
+    case ENODATA:
+        return 61;
+    case ETIME:
+        return 62;
+    case ENOSR:
+        return 63;
+# if 0
+    case ENONET:
+        return 64;
+    case ENOPKG:
+        return 65;
+# endif
+    case ENOLINK:
+        return 66;
+# if 0
+    case EADV:
+        return 67;
+    case ESRMNT:
+        return 68;
+    case ECOMM:
+        return 69;
+# endif
+    case EPROTO:
+        return 70;
+    case EMULTIHOP:
+        return 71;
+# if 0
+    case EDOTDOT:
+        return 72;
+# endif
+    case EBADMSG:
+        return 73;
+    case EOVERFLOW:
+        return 74;
+# if 0
+    case ENOTUNIQ:
+        return 75;
+    case EBADFD:                /* Note: not EBADF */
+        return 77;
+    case EREMCHG:
+        return 78;
+    case ELIBACC:
+        return 79;
+    case ELIBBAD:
+        return 80;
+    case ELIBSCN:
+        return 81;
+    case ELIBMAX:
+        return 82;
+    case ELIBEXEC:
+        return 83;
+#endif
+    case EILSEQ:
+        return 84;
+#if 0
+    case ERESTART:              /* XXX not the same thing */
+        return 85;
+#endif
+#if 0
+    case ESTRPIPE:
+        return 86;
+#endif
+    case EUSERS:
+        return 87;
+    case ENOTSOCK:
+        return 88;
+    case EDESTADDRREQ:
+        return 89;
+    case EMSGSIZE:
+        return 90;
+    case EPROTOTYPE:
+        return 91;
+    case ENOPROTOOPT:
+        return 92;
+    case EPROTONOSUPPORT:
+        return 93;
+    case ESOCKTNOSUPPORT:
+        return 94;
+    case EOPNOTSUPP:
+        return 95;
+    case EPFNOSUPPORT:
+        return 96;
+    case EAFNOSUPPORT:
+        return 97;
+    case EADDRINUSE:
+        return 98;
+    case EADDRNOTAVAIL:
+        return 99;
+    case ENETDOWN:
+        return 100;
+    case ENETUNREACH:
+        return 101;
+    case ENETRESET:
+        return 102;
+    case ECONNABORTED:
+        return 103;
+    case ECONNRESET:
+        return 104;
+    case ENOBUFS:
+        return 105;
+    case EISCONN:
+        return 106;
+    case ENOTCONN:
+        return 107;
+    case ESHUTDOWN:
+        return 108;
+    case ETOOMANYREFS:
+        return 109;
+    case ETIMEDOUT:
+        return 110;
+    case ECONNREFUSED:
+        return 111;
+    case EHOSTDOWN:
+        return 112;
+    case EHOSTUNREACH:
+        return 113;
+    case EALREADY:
+        return 114;
+    case EINPROGRESS:
+        return 115;
+    case ESTALE:
+        return 116;
+# if 0
+    case EUCLEAN:
+        return 117;
+    case ENOTNAM:
+        return 118;
+    case ENAVAIL:
+        return 119;
+    case EISNAM:
+        return 120;
+    case EREMOTEIO:
+        return 121;
+# endif
+    case EDQUOT:
+        return 122;
+# if 0
+    case ENOMEDIUM:
+        return 123;
+    case EMEDIUMTYPE:
+        return 124;
+# endif
+    case ECANCELED:
+        return 125;
+# if 0
+    case ENOKEY:
+        return 126;
+    case EKEYEXPIRED:
+        return 127;
+    case EKEYREVOKED:
+        return 128;
+    case EKEYREJECTED:
+        return 129;
+    case EOWNERDEAD:
+        return 130;
+    case ENOTRECOVERABLE:
+        return 131;
+    case ERFKILL:
+        return 132;
+    case EHWPOISON:
+        return 133;
+# endif
+        /* extras */
+    case ENOTSUP:
+        return EOPNOTSUPP;
+    case ENOATTR:
+        return ENODATA;
+    default:
+        return EIO;
+    }
 #else
 #error Missing errno translation to Linux for this host system
 #endif
@@ -164,13 +456,13 @@ static inline int openat_file(int dirfd,
 {
     int fd, serrno, ret;
 
-#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD)
+#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD) && defined(O_NOATIME)
 again:
 #endif
     fd = qemu_openat(dirfd, name, flags | O_NOFOLLOW | O_NOCTTY | O_NONBLOCK,
                      mode);
     if (fd == -1) {
-#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD)
+#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD) && defined(O_NOATIME)
         if (errno == EPERM && (flags & O_NOATIME)) {
             /*
              * The client passed O_NOATIME but we lack permissions to honor it.
@@ -229,6 +521,7 @@ ssize_t fremovexattrat_nofollow(int dirf
  * so ensure it is manually injected earlier and call here when
  * needed.
  */
+#if defined(CONFIG_LINUX) || defined(CONFIG_DARWIN)
 static inline off_t qemu_dirent_off(struct dirent *dent)
 {
 #ifdef CONFIG_DARWIN
@@ -237,6 +530,7 @@ static inline off_t qemu_dirent_off(stru
     return dent->d_off;
 #endif
 }
+#endif
 
 /**
  * qemu_dirent_dup() - Duplicate directory entry @dent.
