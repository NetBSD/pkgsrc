# $NetBSD: bootstrap.mk,v 1.1.1.1 2009/10/14 11:26:15 tnn Exp $

ONLY_FOR_PLATFORM=	NetBSD-[456].*-i386 NetBSD-[456].*-x86_64

BOOT.nb4-i386=		bootstrap-jdk-7-bin-netbsd-4-i386-20091012.tar.bz2
# not yet
#BOOT.nb4-amd64=		bootstrap-jdk-7-bin-netbsd-4-amd64-20091013.tar.bz2
BOOT.nb5-i386=		bootstrap-jdk-7-bin-netbsd-5-i386-20090926.tar.bz2
BOOT.nb5-amd64=		bootstrap-jdk-7-bin-netbsd-5-amd64-20090925.tar.bz2
BOOT.nb6-i386=		bootstrap-jdk-7-bin-netbsd-6-i386-20091014.tar.bz2
BOOT.nb6-amd64=		bootstrap-jdk-7-bin-netbsd-6-amd64-20091013.tar.bz2

.if !empty(MACHINE_PLATFORM:MNetBSD-4.[0-8]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb4-i386}
EXTRACT_ONLY+=		${BOOT.nb4-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-4.[0-8]*-amd64) || make(distinfo)
DISTFILES+=		${BOOT.nb4-amd64}
EXTRACT_ONLY+=		${BOOT.nb4-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb5-i386}
EXTRACT_ONLY+=		${BOOT.nb5-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb5-amd64}
EXTRACT_ONLY+=		${BOOT.nb5-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-i386) || make(distinfo) || \
    !empty(MACHINE_PLATFORM:MNetBSD-5.99.*-i386)
DISTFILES+=		${BOOT.nb6-i386}
EXTRACT_ONLY+=		${BOOT.nb6-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-x86_64) || make(distinfo) || \
    !empty(MACHINE_PLATFORM:MNetBSD-5.99.*-x86_64)
DISTFILES+=		${BOOT.nb6-amd64}
EXTRACT_ONLY+=		${BOOT.nb6-amd64}
.endif

ALT_BOOTDIR=		${WRKDIR}/bootstrap
