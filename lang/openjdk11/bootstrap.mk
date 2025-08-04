# $NetBSD: bootstrap.mk,v 1.10 2025/08/04 13:22:05 pho Exp $

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 080000
PKG_FAIL_REASON+=		"Only supports NetBSD >= 8"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) && ${OPSYS_VERSION} < 090400
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9.4"
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-i386
BOOT.nb7-i386=			bootstrap-jdk-1.11.0.5.8-netbsd-7-i386-20190928.tar.xz
SITES.${BOOT.nb7-i386}=		${MASTER_SITE_LOCAL:=openjdk11/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.nb7-i386}
EXTRACT_ONLY+=			${BOOT.nb7-i386}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-x86_64
BOOT.nb7-amd64=			bootstrap-jdk-1.11.0.5.8-netbsd-7-amd64-20190928.tar.xz
SITES.${BOOT.nb7-amd64}=	${MASTER_SITE_LOCAL:=openjdk11/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb7-amd64}
EXTRACT_ONLY+=			${BOOT.nb7-amd64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
BOOT.nb9-aarch64=		bootstrap-jdk-1.11.0.27.6-netbsd-9-aarch64-20250804.tar.xz
SITES.${BOOT.nb9-aarch64}=	${MASTER_SITE_LOCAL:=openjdk11/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-aarch64}
EXTRACT_ONLY+=			${BOOT.nb9-aarch64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-earmv[67]hf
BOOT.nb8-earmv6hf=		bootstrap-jdk-1.11.0.15.10-netbsd-8-earmv6hf-20220525.tar.xz
SITES.${BOOT.nb8-earmv6hf}=	${MASTER_SITE_LOCAL:=openjdk11/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf) || make(distinfo)
DISTFILES+=			${BOOT.nb8-earmv6hf}
EXTRACT_ONLY+=			${BOOT.nb8-earmv6hf}
.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib:${ALT_BOOTDIR}/lib/jli

ALT_BOOTDIR=		${WRKDIR}/bootstrap
