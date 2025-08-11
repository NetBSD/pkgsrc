# $NetBSD: bootstrap.mk,v 1.3 2025/08/11 18:06:32 pho Exp $

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) && ${OPSYS_VERSION} < 090400
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9.4"
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-i386
BOOT.nb9-i386=			bootstrap-jdk-1.21.0.1.12-netbsd-9-i386-20231207.tar.xz
SITES.${BOOT.nb9-i386}=		${MASTER_SITE_LOCAL:=openjdk21/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.nb9-i386}
EXTRACT_ONLY+=			${BOOT.nb9-i386}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-x86_64
BOOT.nb9-amd64=			bootstrap-jdk-1.21.0.1.12-netbsd-9-amd64-20231207.tar.xz
SITES.${BOOT.nb9-amd64}=	${MASTER_SITE_LOCAL:=openjdk21/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-amd64}
EXTRACT_ONLY+=			${BOOT.nb9-amd64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
BOOT.nb10-aarch64=		bootstrap-jdk-1.21.0.7.6-netbsd-10-aarch64-20250811.tar.xz
SITES.${BOOT.nb10-aarch64}=	${MASTER_SITE_LOCAL:=openjdk21/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.nb10-aarch64}
EXTRACT_ONLY+=			${BOOT.nb10-aarch64}
.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-earmv[67]hf
#BOOT.nb9-earmv6hf=		bootstrap-jdk-1.17.0.3.7-netbsd-9-earmv6hf-20220525.tar.xz
#SITES.${BOOT.nb9-earmv6hf}=	${MASTER_SITE_LOCAL:=openjdk21/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-earmv6hf}
#EXTRACT_ONLY+=			${BOOT.nb9-earmv6hf}
#.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR=		${WRKDIR}/bootstrap
