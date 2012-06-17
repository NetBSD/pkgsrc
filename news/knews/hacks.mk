# $NetBSD: hacks.mk,v 1.1 2012/06/17 00:10:40 tron Exp $

### [Sun 17 Jun 2012 00:05:38 UTC : tron]
### GCC 4.2.1 (Based on Apple Inc. build 5658) as shipped with
### Mac OS X Lion gets stuck in an endless loop while compiling
### this package.

.if !empty(MACHINE_PLATFORM:MDarwin-11.*-i386)
PKG_HACKS+=		macosx-lion-compiler-hang
BUILDLINK_TRANSFORM+=	rename:-O2:-O1
.endif
