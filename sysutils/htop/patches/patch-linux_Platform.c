$NetBSD: patch-linux_Platform.c,v 1.1 2017/11/24 02:06:13 maya Exp $

Workaround differences in counting memory netbsd vs. linux.
PR 52669 - a bogus value is displayed for used memory because this
quantity becomes negative.

--- linux/Platform.c.orig	2016-02-02 14:58:45.000000000 +0000
+++ linux/Platform.c
@@ -200,7 +200,9 @@ void Platform_setMemoryValues(Meter* thi
    long int usedMem = pl->usedMem;
    long int buffersMem = pl->buffersMem;
    long int cachedMem = pl->cachedMem;
+#ifndef __NetBSD__
    usedMem -= buffersMem + cachedMem;
+#endif
    this->total = pl->totalMem;
    this->values[0] = usedMem;
    this->values[1] = buffersMem;
