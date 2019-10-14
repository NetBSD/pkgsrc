# $NetBSD: bootstrap.mk,v 1.2 2019/10/14 07:58:50 tnn Exp $

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64
BOOT.nb7-i386=		bootstrap-jdk-1.11.0.5.8-netbsd-7-i386-20190928.tar.xz
SITES.${BOOT.nb7-i386}=	${MASTER_SITE_LOCAL:=openjdk11/}
BOOT.nb7-amd64=		bootstrap-jdk-1.11.0.5.8-netbsd-7-amd64-20190928.tar.xz
SITES.${BOOT.nb7-amd64}=${MASTER_SITE_LOCAL:=openjdk11/}

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb7-i386}
EXTRACT_ONLY+=		${BOOT.nb7-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb7-amd64}
EXTRACT_ONLY+=		${BOOT.nb7-amd64}
.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR=		${WRKDIR}/bootstrap
