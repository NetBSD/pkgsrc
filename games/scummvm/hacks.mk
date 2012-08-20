# $NetBSD: hacks.mk,v 1.3 2012/08/20 06:50:21 tron Exp $

### [Sun 17 Jun 2012 00:21:30 UTC : tron]
### G++ 4.2.1 (Based on Apple Inc. build 5658) as shipped with
### Mac OS X Lion crashes with a segmentation fault while compiling
### "engines/queen/journal.cpp". Disabling the optimizer prevents
### the crash.

.if !empty(MACHINE_PLATFORM:MDarwin-11.*-i386)
PKG_HACKS+=		macosx-lion-compiler-crash
BUILDLINK_TRANSFORM+=	rm:-O2
.endif
