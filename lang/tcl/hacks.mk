# $NetBSD: hacks.mk,v 1.1 2004/11/16 22:44:51 jlam Exp $

### [Wed Jul 25 19:42:58 UTC 2001 : jlam]
### Force no optimization (-O0) on NetBSD-1.5.x/m68k machines as there
### appears to be an optimization bug that causes the build to fail
### (pkg/13395).  The problem appeared in the original PR on an Amiga
### running NetBSD 1.5.1 and also on a mac68k running NetBSD 1.5.1.
### This workaround was tested on the mac68k system (kindly provided
### by Jon Lindgren).
###
.if !empty(MACHINE_PLATFORM:MNetBSD-1.5*-m68k)
PKG_HACKS+=		netbsd-1-5-m68k-codegen
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.endif
