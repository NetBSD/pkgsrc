$NetBSD: patch-misc.h,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- use a bit of const

--- /dev/null	2012-12-26 19:42:59.000000000 +0000
+++ misc.h
@@ -0,0 +1,32 @@
+#include <sys/types.h> /* for time_t, size_t */
+
+/* fileio.c */
+void putcode(unsigned int code);
+void putcodew(unsigned int code);
+int getcode(void);
+void ungetcode(int code);
+void preread(void *cp);
+time_t filedate(int fd);
+void filesetdate(const char *name, time_t tim);
+void preread(void *cp);
+int isdir(const char *name);
+
+/* codetoeuc.c */
+unsigned int CodeToEuc(unsigned int);
+
+/* codetojis.c */
+void SetJisMode(int mode);
+unsigned int CodeToJis(unsigned int code);
+void setjismode(void);
+
+/* codetosjis.c */
+unsigned int CodeToSjis(unsigned int code);
+
+/* codetozen.c */
+unsigned int CodeToZen(unsigned int code);
+
+/* euctocode.c */
+unsigned int EucToCode(unsigned int code);
+
+/* sjistocode.c */
+unsigned int SjisToCode(unsigned int code);
