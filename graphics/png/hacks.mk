# $NetBSD: hacks.mk,v 1.4 2014/12/15 11:46:35 jperkin Exp $

.if !defined(PNG_HACKS_MK)
PNG_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### gcc-4.5.3 in NetBSD/arm 6.1 causes SEGV in some png functions.
### -O works around, and there is a report that -O2 -fno-ipa-sra is enough.
### See PR/47798 for details.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm) && !empty(CC_VERSION:Mgcc-4.5.*)
# XXX: is there any good way to replace the default -O2 with multiple args?
#PKG_HACKS+=		optimisation
#BUILDLINK_TRANSFORM+=	opt:-O[2-9]*:-O2 -fno-ipa-sra
CFLAGS+=-O2 -fno-ipa-sra
.endif

.endif	# PNG_HACKS_MK
