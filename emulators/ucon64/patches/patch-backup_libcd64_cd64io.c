$NetBSD: patch-backup_libcd64_cd64io.c,v 1.2 2019/07/07 22:47:57 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- backup/libcd64/cd64io.c.orig	2019-05-06 06:48:17.000000000 +0000
+++ backup/libcd64/cd64io.c
@@ -41,7 +41,20 @@
 
 #ifdef CD64_USE_RAWIO
 
+static INLINE uint8_t inb2(uint16_t);
+static INLINE void outb2(uint8_t, uint16_t);
+
 #if defined _WIN32 || defined __CYGWIN__
+#ifdef _MSC_VER
+#pragma warning(push)
+#pragma warning(disable: 4255) /* 'function' : no function prototype given: converting '()' to '(void)' */
+#pragma warning(disable: 4668) /* 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives' */
+#pragma warning(disable: 4820) /* 'bytes' bytes padding added after construct 'member_name' */
+#endif
+#include <windows.h>                            /* defines _WIN32 (checks for   */
+#ifdef _MSC_VER                                 /*  __CYGWIN__ must come first) */
+#pragma warning(pop)
+#endif
 #ifdef __CYGWIN__
 #include <dlfcn.h>
 
@@ -73,10 +86,8 @@ static short int (WINAPI *IsDriverInstal
 static unsigned char (__stdcall *DlPortReadPortUchar)(unsigned short) = NULL;
 static void (__stdcall *DlPortWritePortUchar)(unsigned short, unsigned char) = NULL;
 
-static INLINE uint8_t inb(uint16_t);
-static INLINE void outb(uint8_t, uint16_t);
-static uint8_t (*input_byte)(uint16_t) = inb;
-static void (*output_byte)(uint8_t, uint16_t) = outb;
+static uint8_t (*input_byte)(uint16_t) = inb2;
+static void (*output_byte)(uint8_t, uint16_t) = outb2;
 #endif
 
 #ifdef  __BEOS__
@@ -774,9 +785,8 @@ static LONG new_exception_filter(LPEXCEP
 #endif
 #endif /* _WIN32 || __CYGWIN__ */
 
-#if ((defined _WIN32 || defined __CYGWIN__ || defined __BEOS__) && \
-    (defined __i386__ || defined __x86_64__)) || defined _MSC_VER
-static INLINE uint8_t inb(uint16_t port) {
+#if defined __i386__ || defined __x86_64__ || defined _MSC_VER
+static INLINE uint8_t inb2(uint16_t port) {
 
 #ifdef __BEOS__
 	st_ioport_t temp;
@@ -785,27 +795,30 @@ static INLINE uint8_t inb(uint16_t port)
 	ioctl(io_portfd, 'r', &temp, 0);
 
 	return temp.data8;
-#else /* Win32 */
+#elif defined _WIN32 || defined __CYGWIN__
 	if (io_driver_found) return input_byte(port);
-	else {
+	else
 #ifdef _MSC_VER
 #ifdef _M_IX86
-		return (unsigned char) _inp(port);
+		return (uint8_t) _inp(port);
 #endif
-#else
-		unsigned char byte;
+#endif
+#endif /* _WIN32 || __CYGWIN__ */
+#if defined __MINGW32__ || defined __CYGWIN__ || \
+    ((defined __i386__ || defined __x86_64__) && !defined __BEOS__)
+	{
+		uint8_t byte;
 		__asm__ __volatile__
 		("inb %1, %0"
 		  : "=a" (byte)
 		  : "d" (port)
 		);
 		return byte;
-#endif
 	}
 #endif
 }
 
-static INLINE void outb(uint8_t byte, uint16_t port) {
+static INLINE void outb2(uint8_t byte, uint16_t port) {
 
 #ifdef __BEOS__
 	st_ioport_t temp;
@@ -813,24 +826,27 @@ static INLINE void outb(uint8_t byte, ui
 	temp.port = port;
 	temp.data8 = byte;
 	ioctl(io_portfd, 'w', &temp, 0);
-#else /* Win32 */
+#elif defined _WIN32 || defined __CYGWIN__
 	if (io_driver_found) output_byte(byte, port);
-	else {
+	else
 #ifdef _MSC_VER
 #ifdef _M_IX86
 		_outp(port, byte);
 #endif
-#else
+#endif
+#endif /* _WIN32 || __CYGWIN__ */
+#if defined __MINGW32__ || defined __CYGWIN__ || \
+    ((defined __i386__ || defined __x86_64__) && !defined __BEOS__)
+	{
 		__asm__ __volatile__
 		("outb %1, %0"
 		  :
 		  : "d" (port), "a" (byte)
 		);
-#endif
 	}
 #endif
 }
-#endif /* inb/outb defs */
+#endif /* inb2/outb2 defs */
 
 int cd64_open_rawio(struct cd64_t *cd64) {
 
@@ -1112,8 +1128,8 @@ int cd64_close_rawio(struct cd64_t *cd64
 	close_module(io_driver, cd64);
 	io_driver = NULL;
 	io_driver_found = 0;
-	input_byte = inb;
-	output_byte = outb;
+	input_byte = inb2;
+	output_byte = outb2;
 #endif
 
 	return 1;
@@ -1127,7 +1143,7 @@ static INLINE int cd64_wait_rawio(struct
 	i = 0;
 
 	if (cd64->using_ppa) {
-		status = inb((uint16_t) (cd64->port+1));
+		status = inb2((uint16_t) (cd64->port+1));
 
 		while (status & 0x80) {
 			i++;
@@ -1136,15 +1152,15 @@ static INLINE int cd64_wait_rawio(struct
 				 * Try to knock some sense into it. */
 				uint8_t dir = 1;
 				status = 0x06 | (dir << 5);
-				outb(status, (uint16_t) (cd64->port+2));
+				outb2(status, (uint16_t) (cd64->port+2));
 
 				dir = 0;
 				status = 0x04 | (dir << 5);
-				outb(status, (uint16_t) (cd64->port+2));
+				outb2(status, (uint16_t) (cd64->port+2));
 				status = 0x05 | (dir << 5);
-				outb(status, (uint16_t) (cd64->port+2));
+				outb2(status, (uint16_t) (cd64->port+2));
 				status = 0x04 | (dir << 5);
-				outb(status, (uint16_t) (cd64->port+2));
+				outb2(status, (uint16_t) (cd64->port+2));
 
 				reset_tries++;
 				i = 0;
@@ -1155,14 +1171,14 @@ static INLINE int cd64_wait_rawio(struct
 				break;
 			}
 
-			status = inb((uint16_t) (cd64->port+1));
+			status = inb2((uint16_t) (cd64->port+1));
 		}
 	}
 	else { /* Comms link */
-		status = inb((uint16_t) (cd64->port+2));
+		status = inb2((uint16_t) (cd64->port+2));
 		while (status & 1) {
 			/* Do we need to handle a stuck situation here? */
-			status = inb((uint16_t) (cd64->port+2));
+			status = inb2((uint16_t) (cd64->port+2));
 		}
 	}
 
@@ -1181,10 +1197,10 @@ int cd64_xfer_rawio(struct cd64_t *cd64,
 		if (delayms) MSLEEP(delayms);
 		dir = 1;
 		ctl = 0x06 | (dir << 5);
-		outb(ctl, (uint16_t) (cd64->port+2));
+		outb2(ctl, (uint16_t) (cd64->port+2));
 		if (delayms) MSLEEP(delayms);
 		if (rd) {
-			*rd = inb((uint16_t) cd64->port);
+			*rd = inb2((uint16_t) cd64->port);
 #if DEBUG_LOWLEVEL
 			printf("got %xh", *rd);
 			if (*rd > 0x20) printf(" (%c)", *rd);
@@ -1195,10 +1211,10 @@ int cd64_xfer_rawio(struct cd64_t *cd64,
 		if (delayms) MSLEEP(delayms);
 		dir = 0;
 		ctl = 0x04 | (dir << 5);
-		outb(ctl, (uint16_t) (cd64->port+2));
+		outb2(ctl, (uint16_t) (cd64->port+2));
 		if (delayms) MSLEEP(delayms);
 		if (wr) {
-			outb(*wr, (uint16_t) cd64->port);
+			outb2(*wr, (uint16_t) cd64->port);
 #if DEBUG_LOWLEVEL
 			printf("put %xh", *wr);
 			if (*wr > 0x20) printf(" (%c)", *wr);
@@ -1207,15 +1223,15 @@ int cd64_xfer_rawio(struct cd64_t *cd64,
 		}
 		if (delayms) MSLEEP(delayms);
 		ctl = 0x05 | (dir << 5);
-		outb(ctl, (uint16_t) (cd64->port+2));
+		outb2(ctl, (uint16_t) (cd64->port+2));
 		if (delayms) MSLEEP(delayms);
 		ctl = 0x04 | (dir << 5);
-		outb(ctl, (uint16_t) (cd64->port+2));
+		outb2(ctl, (uint16_t) (cd64->port+2));
 	}
 	else { /* Comms link */
-		outb(*wr, (uint16_t) cd64->port);
+		outb2(*wr, (uint16_t) cd64->port);
 		if (!cd64_wait_rawio(cd64)) { return 0; }
-		*rd = inb((uint16_t) cd64->port);
+		*rd = inb2((uint16_t) cd64->port);
 	}
 
 	return 1;
