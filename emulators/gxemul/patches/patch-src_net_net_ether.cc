$NetBSD: patch-src_net_net_ether.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add some generic Ethernet routines used for address filtering.

--- /dev/null	2020-10-05 22:44:11.028207457 +0000
+++ src/net/net_ether.cc	2020-10-05 23:01:48.744053911 +0000
@@ -0,0 +1,143 @@
+/*  
+ *  Copyright (C) 2020 Jason R. Thorpe.  All rights reserved.
+ * 
+ *  Redistribution and use in source and binary forms, with or without
+ *  modification, are permitted provided that the following conditions are met:
+ *
+ *  1. Redistributions of source code must retain the above copyright
+ *     notice, this list of conditions and the following disclaimer.
+ *  2. Redistributions in binary form must reproduce the above copyright
+ *     notice, this list of conditions and the following disclaimer in the
+ *     documentation and/or other materials provided with the distribution.
+ *  3. The name of the author may not be used to endorse or promote products
+ *     derived from this software without specific prior written permission.
+ *      
+ *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
+ *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ *  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
+ *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ *  SUCH DAMAGE.
+ */
+
+/*
+ *  Common Ethernet support routines.
+ */
+
+#include <sys/types.h>
+#include <string.h>
+
+#include "misc.h"
+#include "net.h"
+
+
+/*
+ *  net_ether_eq():
+ *
+ *  Compare two Ethernet addresses for equality.
+ */
+int net_ether_eq(const uint8_t *a1, const uint8_t *a2)
+{
+
+	return a1[5] == a2[5] &&
+	       a1[4] == a2[4] &&
+	       a1[3] == a2[3] &&
+	       a1[2] == a2[2] &&
+	       a1[1] == a2[1] &&
+	       a1[0] == a2[0];
+}
+
+
+/*
+ *  net_ether_broadcast():
+ *
+ *  Returns 1 if the specified destination address is the Ethernet
+ *  broadcast address.
+ */
+int net_ether_broadcast(const uint8_t *a)
+{
+	static const uint8_t ether_broadcast[6] =
+	    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
+
+	return net_ether_eq(a, ether_broadcast);
+}
+
+
+/*
+ *  net_ether_multicast():
+ *
+ *  Returns 1 if the specfied destination address is an Ethernet
+ *  multicast address.
+ *
+ *  Note that this also matches Ethernet broadcast, which is just
+ *  a special case of multicast.
+ */
+int net_ether_multicast(const uint8_t *a)
+{
+	return (*a & 0x01);
+}
+
+
+/*
+ * Copyright (c) 1982, 1989, 1993
+ *      The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ *      @(#)if_ethersubr.c      8.2 (Berkeley) 4/4/96
+ */
+
+
+/*
+ *  net_ether_crc32_le():
+ *
+ *  Fast table-driven little-endian Ethernet CRC generator.
+ */
+uint32_t net_ether_crc32_le(const uint8_t *buf, size_t len)
+{
+	static const uint32_t crctab[] = {
+		0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
+		0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
+		0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
+		0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
+	};
+	uint32_t crc;
+	size_t i;
+
+	crc = 0xffffffffU;	/* initial value */
+
+	for (i = 0; i < len; i++) {
+		crc ^= buf[i];
+		crc = (crc >> 4) ^ crctab[crc & 0xf];
+		crc = (crc >> 4) ^ crctab[crc & 0xf];
+	}
+
+	return crc;
+}
