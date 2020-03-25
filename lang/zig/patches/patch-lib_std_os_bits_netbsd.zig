$NetBSD: patch-lib_std_os_bits_netbsd.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- lib/std/os/bits/netbsd.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/os/bits/netbsd.zig
@@ -1,8 +1,12 @@
 const std = @import("../../std.zig");
 const maxInt = std.math.maxInt;
 
-pub const fd_t = c_int;
-pub const pid_t = c_int;
+pub const fd_t = i32;
+pub const pid_t = i32;
+pub const mode_t = u32;
+pub const ino_t = u64;
+pub const off_t = i64;
+pub const socklen_t = u32;
 
 /// Renamed from `kevent` to `Kevent` to avoid conflict with function name.
 pub const Kevent = extern struct {
@@ -14,12 +18,6 @@ pub const Kevent = extern struct {
     udata: usize,
 };
 
-pub const pthread_attr_t = extern struct {
-    pta_magic: u32,
-    pta_flags: c_int,
-    pta_private: *c_void,
-};
-
 pub const dl_phdr_info = extern struct {
     dlpi_addr: usize,
     dlpi_name: ?[*]const u8,
@@ -27,6 +25,65 @@ pub const dl_phdr_info = extern struct {
     dlpi_phnum: u16,
 };
 
+pub const addrinfo = extern struct {
+    flags: i32,
+    family: i32,
+    socktype: i32,
+    protocol: i32,
+    addrlen: socklen_t,
+    canonname: ?[*]u8,
+    addr: ?*sockaddr,
+    next: ?*addrinfo,
+};
+
+pub const EAI = extern enum(c_int) {
+    /// address family for hostname not supported
+    ADDRFAMILY = 1,
+
+    /// name could not be resolved at this time
+    AGAIN = 2,
+
+    /// flags parameter had an invalid value
+    BADFLAGS = 3,
+
+    /// non-recoverable failure in name resolution
+    FAIL = 4,
+
+    /// address family not recognized
+    FAMILY = 5,
+
+    /// memory allocation failure
+    MEMORY = 6,
+
+    /// no address associated with hostname
+    NODATA = 7,
+
+    /// name does not resolve
+    NONAME = 8,
+
+    /// service not recognized for socket type
+    SERVICE = 9,
+
+    /// intended socket type was not recognized
+    SOCKTYPE = 10,
+
+    /// system error returned in errno
+    SYSTEM = 11,
+
+    /// invalid value for hints
+    BADHINTS = 12,
+
+    /// resolved protocol is unknown
+    PROTOCOL = 13,
+
+    /// argument buffer overflow
+    OVERFLOW = 14,
+
+    _,
+};
+
+pub const EAI_MAX = 15;
+
 pub const msghdr = extern struct {
     /// optional address
     msg_name: ?*sockaddr,
@@ -73,8 +130,6 @@ pub const msghdr_const = extern struct {
     msg_flags: i32,
 };
 
-pub const off_t = i64;
-
 /// Renamed to Stat to not conflict with the stat function.
 /// atime, mtime, and ctime have functions to return `timespec`,
 /// because although this is a POSIX API, the layout and names of
@@ -84,7 +139,7 @@ pub const off_t = i64;
 pub const Stat = extern struct {
     dev: u64,
     mode: u32,
-    ino: u64,
+    ino: ino_t,
     nlink: usize,
 
     uid: u32,
@@ -126,35 +181,71 @@ pub const dirent = extern struct {
     d_reclen: u16,
     d_namlen: u16,
     d_type: u8,
-    d_off: i64,
     d_name: [512]u8,
+
+    pub fn reclen(self: dirent) u16 {
+        return self.d_reclen;
+    }
 };
 
 pub const in_port_t = u16;
 pub const sa_family_t = u8;
 
-pub const sockaddr = extern union {
-    in: sockaddr_in,
-    in6: sockaddr_in6,
+pub const sockaddr = extern struct {
+    /// total length
+    len: u8,
+
+    /// address family
+    family: sa_family_t,
+
+    /// actually longer; address value
+    data: [14]u8,
 };
 
 pub const sockaddr_in = extern struct {
-    len: u8,
-    family: sa_family_t,
+    len: u8 = @sizeOf(sockaddr_in),
+    family: sa_family_t = AF_INET,
     port: in_port_t,
     addr: u32,
-    zero: [8]u8,
+    zero: [8]u8 = [8]u8{ 0, 0, 0, 0, 0, 0, 0, 0 },
 };
 
 pub const sockaddr_in6 = extern struct {
-    len: u8,
-    family: sa_family_t,
+    len: u8 = @sizeOf(sockaddr_in6),
+    family: sa_family_t = AF_INET6,
     port: in_port_t,
     flowinfo: u32,
     addr: [16]u8,
     scope_id: u32,
 };
 
+/// Definitions for UNIX IPC domain.
+pub const sockaddr_un = extern struct {
+    /// total sockaddr length
+    len: u8 = @sizeOf(sockaddr_un),
+
+    /// AF_LOCAL
+    family: sa_family_t = AF_LOCAL,
+
+    /// path name
+    path: [104]u8,
+};
+
+/// get address to use bind()
+pub const AI_PASSIVE = 0x00000001;
+
+/// fill ai_canonname
+pub const AI_CANONNAME = 0x00000002;
+
+/// prevent host name resolution
+pub const AI_NUMERICHOST = 0x00000004;
+
+/// prevent service name resolution
+pub const AI_NUMERICSERV = 0x00000008;
+
+/// only if any address is assigned
+pub const AI_ADDRCONFIG = 0x00000400;
+
 pub const CTL_KERN = 1;
 pub const CTL_DEBUG = 5;
 
@@ -256,31 +347,71 @@ pub const X_OK = 1; // test for execute 
 pub const W_OK = 2; // test for write permission
 pub const R_OK = 4; // test for read permission
 
-pub const O_RDONLY = 0x0000;
-pub const O_WRONLY = 0x0001;
-pub const O_RDWR = 0x0002;
-pub const O_ACCMODE = 0x0003;
-
-pub const O_CREAT = 0x0200;
-pub const O_EXCL = 0x0800;
-pub const O_NOCTTY = 0x8000;
-pub const O_TRUNC = 0x0400;
-pub const O_APPEND = 0x0008;
-pub const O_NONBLOCK = 0x0004;
+/// open for reading only
+pub const O_RDONLY = 0x00000000;
+
+/// open for writing only
+pub const O_WRONLY = 0x00000001;
+
+/// open for reading and writing
+pub const O_RDWR = 0x00000002;
+
+/// mask for above modes
+pub const O_ACCMODE = 0x00000003;
+
+/// no delay
+pub const O_NONBLOCK = 0x00000004;
+
+/// set append mode
+pub const O_APPEND = 0x00000008;
+
+/// open with shared file lock
+pub const O_SHLOCK = 0x00000010;
+
+/// open with exclusive file lock
+pub const O_EXLOCK = 0x00000020;
+
+/// signal pgrp when data ready
+pub const O_ASYNC = 0x00000040;
+
+/// synchronous writes
+pub const O_SYNC = 0x00000080;
+
+/// don't follow symlinks on the last
+pub const O_NOFOLLOW = 0x00000100;
+
+/// create if nonexistent
+pub const O_CREAT = 0x00000200;
+
+/// truncate to zero length
+pub const O_TRUNC = 0x00000400;
+
+/// error if already exists
+pub const O_EXCL = 0x00000800;
+
+/// don't assign controlling terminal
+pub const O_NOCTTY = 0x00008000;
+
+/// write: I/O data completion
 pub const O_DSYNC = 0x00010000;
-pub const O_SYNC = 0x0080;
+
+/// read: I/O completion as for write
 pub const O_RSYNC = 0x00020000;
-pub const O_DIRECTORY = 0x00080000;
-pub const O_NOFOLLOW = 0x00000100;
-pub const O_CLOEXEC = 0x00400000;
 
-pub const O_ASYNC = 0x0040;
+/// use alternate i/o semantics
+pub const O_ALT_IO = 0x00040000;
+
+/// direct I/O hint
 pub const O_DIRECT = 0x00080000;
-pub const O_LARGEFILE = 0;
-pub const O_NOATIME = 0;
-pub const O_PATH = 0;
-pub const O_TMPFILE = 0;
-pub const O_NDELAY = O_NONBLOCK;
+
+/// fail if not a directory
+pub const O_DIRECTORY = 0x00200000;
+
+/// set close on exec
+pub const O_CLOEXEC = 0x00400000;
+
+/// skip search permission checks
+pub const O_SEARCH = 0x00800000;
 
 pub const F_DUPFD = 0;
 pub const F_GETFD = 1;
@@ -295,6 +426,8 @@ pub const F_GETLK = 7;
 pub const F_SETLK = 8;
 pub const F_SETLKW = 9;
 
+pub const FD_CLOEXEC = 1;
+
 pub const SEEK_SET = 0;
 pub const SEEK_CUR = 1;
 pub const SEEK_END = 2;
@@ -312,31 +445,6 @@ pub const SOCK_SEQPACKET = 5;
 pub const SOCK_CLOEXEC = 0x10000000;
 pub const SOCK_NONBLOCK = 0x20000000;
 
-pub const PROTO_ip = 0;
-pub const PROTO_icmp = 1;
-pub const PROTO_igmp = 2;
-pub const PROTO_ggp = 3;
-pub const PROTO_ipencap = 4;
-pub const PROTO_tcp = 6;
-pub const PROTO_egp = 8;
-pub const PROTO_pup = 12;
-pub const PROTO_udp = 17;
-pub const PROTO_xns_idp = 22;
-pub const PROTO_iso_tp4 = 29;
-pub const PROTO_ipv6 = 41;
-pub const PROTO_ipv6_route = 43;
-pub const PROTO_ipv6_frag = 44;
-pub const PROTO_rsvp = 46;
-pub const PROTO_gre = 47;
-pub const PROTO_esp = 50;
-pub const PROTO_ah = 51;
-pub const PROTO_ipv6_icmp = 58;
-pub const PROTO_ipv6_nonxt = 59;
-pub const PROTO_ipv6_opts = 60;
-pub const PROTO_encap = 98;
-pub const PROTO_pim = 103;
-pub const PROTO_raw = 255;
-
 pub const PF_UNSPEC = 0;
 pub const PF_LOCAL = 1;
 pub const PF_UNIX = PF_LOCAL;
@@ -822,4 +930,132 @@ pub fn S_IWHT(m: u32) bool {
     return m & S_IFMT == S_IFWHT;
 }
 
+/// Magic value that specify the use of the current working directory
+/// to determine the target of relative file paths in the openat() and
+/// similar syscalls.
+pub const AT_FDCWD = -100;
+
+/// Check access using effective user and group ID
+pub const AT_EACCESS = 0x0100;
+
+/// Do not follow symbolic links
+pub const AT_SYMLINK_NOFOLLOW = 0x0200;
+
+/// Follow symbolic link
+pub const AT_SYMLINK_FOLLOW = 0x0400;
+
+/// Remove directory instead of file
+pub const AT_REMOVEDIR = 0x0800;
+
 pub const HOST_NAME_MAX = 255;
+
+/// dummy for IP
+pub const IPPROTO_IP = 0;
+
+/// IP6 hop-by-hop options
+pub const IPPROTO_HOPOPTS = 0;
+
+/// control message protocol
+pub const IPPROTO_ICMP = 1;
+
+/// group mgmt protocol
+pub const IPPROTO_IGMP = 2;
+
+/// gateway^2 (deprecated)
+pub const IPPROTO_GGP = 3;
+
+/// IP header
+pub const IPPROTO_IPV4 = 4;
+
+/// IP inside IP
+pub const IPPROTO_IPIP = 4;
+
+/// tcp
+pub const IPPROTO_TCP = 6;
+
+/// exterior gateway protocol
+pub const IPPROTO_EGP = 8;
+
+/// pup
+pub const IPPROTO_PUP = 12;
+
+/// user datagram protocol
+pub const IPPROTO_UDP = 17;
+
+/// xns idp
+pub const IPPROTO_IDP = 22;
+
+/// tp-4 w/ class negotiation
+pub const IPPROTO_TP = 29;
+
+/// DCCP
+pub const IPPROTO_DCCP = 33;
+
+/// IP6 header
+pub const IPPROTO_IPV6 = 41;
+
+/// IP6 routing header
+pub const IPPROTO_ROUTING = 43;
+
+/// IP6 fragmentation header
+pub const IPPROTO_FRAGMENT = 44;
+
+/// resource reservation
+pub const IPPROTO_RSVP = 46;
+
+/// GRE encaps RFC 1701
+pub const IPPROTO_GRE = 47;
+
+/// encap. security payload
+pub const IPPROTO_ESP = 50;
+
+/// authentication header
+pub const IPPROTO_AH = 51;
+
+/// IP Mobility RFC 2004
+pub const IPPROTO_MOBILE = 55;
+
+/// IPv6 ICMP
+pub const IPPROTO_IPV6_ICMP = 58;
+
+/// ICMP6
+pub const IPPROTO_ICMPV6 = 58;
+
+/// IP6 no next header
+pub const IPPROTO_NONE = 59;
+
+/// IP6 destination option
+pub const IPPROTO_DSTOPTS = 60;
+
+/// ISO cnlp
+pub const IPPROTO_EON = 80;
+
+/// Ethernet-in-IP
+pub const IPPROTO_ETHERIP = 97;
+
+/// encapsulation header
+pub const IPPROTO_ENCAP = 98;
+
+/// Protocol indep. multicast
+pub const IPPROTO_PIM = 103;
+
+/// IP Payload Comp. Protocol
+pub const IPPROTO_IPCOMP = 108;
+
+/// VRRP RFC 2338
+pub const IPPROTO_VRRP = 112;
+
+/// Common Address Resolution Protocol
+pub const IPPROTO_CARP = 112;
+
+/// L2TPv3
+pub const IPPROTO_L2TP = 115;
+
+/// SCTP
+pub const IPPROTO_SCTP = 132;
+
+/// PFSYNC
+pub const IPPROTO_PFSYNC = 240;
+
+/// raw IP packet
+pub const IPPROTO_RAW = 255;
