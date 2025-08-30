$NetBSD: patch-src_sysdeps_freebsd.c,v 1.1 2025/08/30 08:24:21 pho Exp $

Apply FreeBSD patch for newer kernel versions:
https://git.srcbox.net/gkrellm/gkrellm/commit/6526b753b2ece3331add6c9dd6af09e7899c67bc

--- src/sysdeps/freebsd.c.orig	2025-01-19 16:02:37.000000000 +0000
+++ src/sysdeps/freebsd.c
@@ -701,9 +701,15 @@ gkrellm_sys_inet_read_tcp_data(void)
 		     xig->xig_len > sizeof(struct xinpgen);
 		     xig = (struct xinpgen *)((char *)xig + xig->xig_len))
 			{
+#if __FreeBSD_version >= 1200026
+			struct xtcpcb *tp = (struct xtcpcb *)xig;
+			struct xinpcb *inp = &tp->xt_inp;
+			struct xsocket *so = &inp->xi_socket;
+#else
 			struct tcpcb *tp = &((struct xtcpcb *)xig)->xt_tp;
 			struct inpcb *inp = &((struct xtcpcb *)xig)->xt_inp;
 			struct xsocket *so = &((struct xtcpcb *)xig)->xt_socket;
+#endif
 
 			/* Ignore sockets for protocols other than tcp. */
 			if (so->xso_protocol != IPPROTO_TCP)
@@ -1441,7 +1447,9 @@ get_data(int iodev, u_char command, int interface, u_c
 		struct smbcmd cmd;
 
 		bzero(&cmd, sizeof(cmd));
+#if __FreeBSD_version < 1100070
 		cmd.data.byte_ptr = (char *)&byte;
+#endif
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
 		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
@@ -1449,6 +1457,9 @@ get_data(int iodev, u_char command, int interface, u_c
 			close(iodev);
 			return FALSE;
 			}
+#if __FreeBSD_version >= 1100070
+		byte = (u_char)cmd.rdata.byte;
+#endif
 		}
 #endif
 	else
