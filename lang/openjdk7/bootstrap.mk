# $NetBSD: bootstrap.mk,v 1.10 2013/10/16 16:51:00 richard Exp $

ONLY_FOR_PLATFORM=	NetBSD-[56].*-i386 NetBSD-[56].*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-[23].*-* SunOS-*-*

BOOT.nb5-i386=		bootstrap-jdk7-bin-netbsd-5-i386-20110811.tar.bz2
BOOT.nb5-amd64=		bootstrap-jdk7-bin-netbsd-5-amd64-20110811.tar.bz2
BOOT.nb6-i386=		bootstrap-jdk7-bin-netbsd-6-i386-20110811.tar.bz2
BOOT.nb6-amd64=		bootstrap-jdk7-bin-netbsd-6-amd64-20110811.tar.bz2
BOOT.df213-i386=	bootstrap-jdk7-bin-dragonfly-2.13-i386-20110811A.tar.xz
# 1.7 partial bootstrap:
BOOT.df213-amd64=	bootstrap-jdk7-bin-dragonfly-2.13-amd64-20110811A.tar.xz
BOOT.df33prebump-i386=	bootstrap-openjdk-7.9.05_2.dfly-3.3-i386.tar.xz
BOOT.df33prebump-amd64=	bootstrap-openjdk-7.9.05_2.dfly-3.3-amd64.tar.xz
BOOT.df35-i386=		bootstrap-openjdk-7.21.11.dfly-3.5-i386.tar.xz
BOOT.df35-amd64=	bootstrap-openjdk-7.21.11.dfly-3.5-amd64.tar.xz
BOOT.common-20110811=	bootstrap-jdk7-bin-common-20110811.tar.bz2

DFBSDBOOTSTRAPSITE=	http://dl.wolfpond.org/openjdk7/
SITES.bootstrap-jdk7-bin-dragonfly-2.13-i386-20110811A.tar.xz=	${DFBSDBOOTSTRAPSITE}
SITES.bootstrap-jdk7-bin-dragonfly-2.13-amd64-20110811A.tar.xz=	${DFBSDBOOTSTRAPSITE}
SITES.bootstrap-openjdk-7.9.05_2.dfly-3.3-i386.tar.xz=	${DFBSDBOOTSTRAPSITE}
SITES.bootstrap-openjdk-7.9.05_2.dfly-3.3-amd64.tar.xz=	${DFBSDBOOTSTRAPSITE}
SITES.bootstrap-openjdk-7.21.11.dfly-3.5-i386.tar.xz=	${DFBSDBOOTSTRAPSITE}
SITES.bootstrap-openjdk-7.21.11.dfly-3.5-amd64.tar.xz=	${DFBSDBOOTSTRAPSITE}

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

.if !empty(MACHINE_PLATFORM:MDragonFly-2.[0-9]*-i386) || \
    !empty(MACHINE_PLATFORM:MDragonFly-3.[0-2]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.df213-i386}
EXTRACT_ONLY+=		${BOOT.df213-i386}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-2.[0-9]*-x86_64) || \
    !empty(MACHINE_PLATFORM:MDragonFly-3.[0-2]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.df213-amd64}
EXTRACT_ONLY+=		${BOOT.df213-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.[3-4]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.df33prebump-i386}
EXTRACT_ONLY+=		${BOOT.df33prebump-i386}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.[3-4]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.df33prebump-amd64}
EXTRACT_ONLY+=		${BOOT.df33prebump-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.[5-9]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.df35-i386}
EXTRACT_ONLY+=		${BOOT.df35-i386}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.[5-9]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.df35-amd64}
EXTRACT_ONLY+=		${BOOT.df35-amd64}
.endif

.if !empty(DISTFILES:M*20110811*) || make(distinfo)
DISTFILES+=		${BOOT.common-20110811}
EXTRACT_ONLY+=		${BOOT.common-20110811}
.endif

.if ${OPSYS} == "SunOS"
BUILDLINK_DEPMETHOD.sun-jdk7?=	build
.include "../../lang/sun-jdk7/buildlink3.mk"
#NB: sun-jdk7 includes sun-jre7/buildlink3.mk
JDK_BOOTDIR=	${BUILDLINK_JAVA_PREFIX.sun-jre7:tA}
MAKE_ENV+=		ALT_JDK_IMPORT_PATH=${JDK_BOOTDIR}
.endif

ALT_BOOTDIR=		${WRKDIR}/bootstrap
