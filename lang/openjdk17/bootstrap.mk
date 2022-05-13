# $NetBSD: bootstrap.mk,v 1.1 2022/05/13 14:24:19 ryoon Exp $


ONLY_FOR_PLATFORM+=		NetBSD-*-i386
BOOT.nb9-i386=			bootstrap-jdk-1.17.0.2.8-netbsd-9-i386-20220506.tar.xz
#SITES.${BOOT.nb9-i386}=		${MASTER_SITE_LOCAL:=openjdk17/}
SITES.${BOOT.nb9-i386}=		https://www.ryoon.net/~ryoon/
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.nb9-i386}
EXTRACT_ONLY+=			${BOOT.nb9-i386}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-9.[0-8]*-x86_64
BOOT.nb9-amd64=			bootstrap-jdk-1.17.0.2.8-netbsd-9-amd64-20220408.tar.xz
#SITES.${BOOT.nb9-amd64}=	${MASTER_SITE_LOCAL:=openjdk17/}
SITES.${BOOT.nb9-amd64}=	https://www.ryoon.net/~ryoon/
.if !empty(MACHINE_PLATFORM:MNetBSD-9.[0-8]*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-amd64}
EXTRACT_ONLY+=			${BOOT.nb9-amd64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-9.9*-x86_64
BOOT.nb10-amd64=		bootstrap-jdk-1.17.0.2.8-netbsd-10-amd64-20220401.tar.xz
#SITES.${BOOT.nb10-amd64}=	${MASTER_SITE_LOCAL:=openjdk17/}
SITES.${BOOT.nb10-amd64}=	https://www.ryoon.net/~ryoon/
.if !empty(MACHINE_PLATFORM:MNetBSD-9.9*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb10-amd64}
EXTRACT_ONLY+=			${BOOT.nb10-amd64}
.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
#BOOT.nb9-aarch64=		bootstrap-jdk-1.11.0.7.10-netbsd-9-aarch64-20200509.tar.xz
#SITES.${BOOT.nb9-aarch64}=	${MASTER_SITE_LOCAL:=openjdk11/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-aarch64}
#EXTRACT_ONLY+=			${BOOT.nb9-aarch64}
#.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR=		${WRKDIR}/bootstrap
