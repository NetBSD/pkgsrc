# $NetBSD: hacks.mk,v 1.2 2014/03/08 11:57:00 obache Exp $

.if !defined(GTAR_BASE_HACKS_MK)
GTAR_BASE_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### gcc-4.5.3 in NetBSD/m68k 6.0_BETA2 gets ICE on compiling mktime.c.
### -O1 works around in this case.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k) && !empty(CC_VERSION:Mgcc-4.5.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rename:-O[2s]*:-O1
.endif

.endif	# GTAR_BASE_HACKS_MK
