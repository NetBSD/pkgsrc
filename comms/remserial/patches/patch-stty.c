$NetBSD: patch-stty.c,v 1.1 2020/02/15 02:26:58 manu Exp $

Fixes for NetBSD build

--- stty.c.orig	2020-02-14 11:21:48.402882118 +0100
+++ stty.c	2020-02-14 11:24:48.883716864 +0100
@@ -21,8 +21,12 @@
 #include <termios.h>
 #include <unistd.h>
 #include <string.h>
 
+#ifdef __NetBSD__
+#include <sys/ioctl_compat.h>
+#endif
+
 #define CFLG	0
 #define IFLG	1
 #define OFLG	2
 #define LFLG	3
@@ -107,26 +111,42 @@
 	{ "onlcr",	OFLG,	ONLCR,		ONLCR	},
 	{ "ocrnl",	OFLG,	OCRNL,		OCRNL	},
 	{ "onocr",	OFLG,	ONOCR,		ONOCR	},
 	{ "onlret",	OFLG,	ONLRET,		ONLRET	},
+#ifdef OFILL 	// Missing on NetBSD
 	{ "ofil",	OFLG,	OFILL,		OFILL	},
+#endif
+#ifdef OFDEL 	// Missing on NetBSD
 	{ "ofdel",	OFLG,	OFDEL,		OFDEL	},
+#endif
+#ifdef NLDLY 	// Missing on NetBSD
 	{ "nl0",	OFLG,	NLDLY,		NL0	},
 	{ "nl1",	OFLG,	NLDLY,		NL1	},
+#endif
+#ifdef CRDLY 	// Missing on NetBSD
 	{ "cr0",	OFLG,	CRDLY,		CR0	},
 	{ "cr1",	OFLG,	CRDLY,		CR1	},
 	{ "cr2",	OFLG,	CRDLY,		CR2	},
 	{ "cr3",	OFLG,	CRDLY,		CR3	},
+#endif
+#ifdef TABDLY	// Missing on NetBSD
 	{ "tab0",	OFLG,	TABDLY,		TAB0	},
 	{ "tab1",	OFLG,	TABDLY,		TAB1	},
 	{ "tab2",	OFLG,	TABDLY,		TAB2	},
 	{ "tab3",	OFLG,	TABDLY,		TAB3	},
+#endif
+#ifdef BSDLY	// Missing on NetBSD
 	{ "bs0",	OFLG,	BSDLY,		BS0	},
 	{ "bs1",	OFLG,	BSDLY,		BS1	},
+#endif
+#ifdef VTDLY	// Missing on NetBSD
 	{ "vt0",	OFLG,	VTDLY,		VT0	},
 	{ "vt1",	OFLG,	VTDLY,		VT1	},
+#endif
+#ifdef FFDLY	// Missing on NetBSD
 	{ "ff0",	OFLG,	FFDLY,		FF0	},
 	{ "ff1",	OFLG,	FFDLY,		FF1	},
+#endif
 	{ "isig",	LFLG,	ISIG,		ISIG	},
 	{ "icanon",	LFLG,	ICANON,		ICANON	},
 #ifdef XCASE	// Missing on OSX, FreeBSD
 	{ "xcase",	LFLG,	XCASE,		XCASE	},
