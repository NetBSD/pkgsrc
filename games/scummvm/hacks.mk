# $NetBSD: hacks.mk,v 1.4 2023/08/02 16:57:39 adam Exp $

### [Sun 17 Jun 2012 00:21:30 UTC : tron]
### G++ 4.2.1 (Based on Apple Inc. build 5658) as shipped with
### Mac OS X Lion crashes with a segmentation fault while compiling
### "engines/queen/journal.cpp". Disabling the optimizer prevents
### the crash.

.if ${MACHINE_PLATFORM:MDarwin-11.*-i386}
PKG_HACKS+=		macosx-lion-compiler-crash
BUILDLINK_TRANSFORM+=	rm:-O2
.endif
