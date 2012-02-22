# $NetBSD: bootstrap.mk,v 1.5 2012/02/22 13:25:14 ryoon Exp $

ONLY_FOR_PLATFORM=	NetBSD-[56].*-i386 NetBSD-[56].*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-2.*-i386

BOOT.nb5-i386=		bootstrap-jdk7-bin-netbsd-5-i386-20110811.tar.bz2
BOOT.nb5-amd64=		bootstrap-jdk7-bin-netbsd-5-amd64-20110811.tar.bz2
BOOT.nb6-i386=		bootstrap-jdk7-bin-netbsd-6-i386-20110811.tar.bz2
BOOT.nb6-amd64=		bootstrap-jdk7-bin-netbsd-6-amd64-20110811.tar.bz2
BOOT.df210-i386=	bootstrap-jdk7-bin-dragonfly-2.10-i386-20110811.tar.bz2
BOOT.common-20110811=	bootstrap-jdk7-bin-common-20110811.tar.bz2

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb5-i386}
EXTRACT_ONLY+=		${BOOT.nb5-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb5-amd64}
EXTRACT_ONLY+=		${BOOT.nb5-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-i386) || make(distinfo) || \
    !empty(MACHINE_PLATFORM:MNetBSD-5.99.*-i386) || \
    !empty(MACHINE_PLATFORM:MNetBSD-6.99.*-i386)
DISTFILES+=		${BOOT.nb6-i386}
EXTRACT_ONLY+=		${BOOT.nb6-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-x86_64) || make(distinfo) || \
    !empty(MACHINE_PLATFORM:MNetBSD-5.99.*-x86_64) || \
    !empty(MACHINE_PLATFORM:MNetBSD-6.99.*-x86_64)
DISTFILES+=		${BOOT.nb6-amd64}
EXTRACT_ONLY+=		${BOOT.nb6-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-*-i386) || make(distinfo)
DISTFILES+=		${BOOT.df210-i386}
EXTRACT_ONLY+=		${BOOT.df210-i386}
.endif

.if !empty(DISTFILES:M*20110811*) || make(distinfo)
DISTFILES+=		${BOOT.common-20110811}
EXTRACT_ONLY+=		${BOOT.common-20110811}
.endif

ALT_BOOTDIR=		${WRKDIR}/bootstrap
