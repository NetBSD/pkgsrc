# $NetBSD: bootstrap.mk,v 1.5 2022/05/15 22:44:24 tnn Exp $

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) && ${OPSYS_VERSION} < 099983
PKG_FAIL_REASON+=		"PR 55248: please update to NetBSD >= 9.99.83 to use this package"
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-i386
BOOT.nb9-i386=			bootstrap-jdk-1.17.0.3.7-netbsd-9-i386-20220515.tar.xz
SITES.${BOOT.nb9-i386}=		${MASTER_SITE_LOCAL:=openjdk17/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.nb9-i386}
EXTRACT_ONLY+=			${BOOT.nb9-i386}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-x86_64
BOOT.nb9-amd64=			bootstrap-jdk-1.17.0.3.7-netbsd-9-amd64-20220515.tar.xz
SITES.${BOOT.nb9-amd64}=	${MASTER_SITE_LOCAL:=openjdk17/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-amd64}
EXTRACT_ONLY+=			${BOOT.nb9-amd64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
BOOT.nb9-aarch64=		bootstrap-jdk-1.17.0.3.7-netbsd-9-aarch64-20220516.tar.xz
SITES.${BOOT.nb9-aarch64}=	${MASTER_SITE_LOCAL:=openjdk17/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-aarch64}
EXTRACT_ONLY+=			${BOOT.nb9-aarch64}
.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR=		${WRKDIR}/bootstrap
