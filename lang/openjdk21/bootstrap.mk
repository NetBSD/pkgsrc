# $NetBSD: bootstrap.mk,v 1.1 2023/11/22 14:06:50 ryoon Exp $

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9"
.endif

#.if (!empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) ||!empty(MACHINE_PLATFORM:MNetBSD-*-*earm*)) && ${OPSYS_VERSION} < 099983
#PKG_FAIL_REASON+=		"PR 55248: please update to NetBSD >= 9.99.83 to use this package"
#.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-i386
#BOOT.nb9-i386=			bootstrap-jdk-1.21.0.1.12-netbsd-9-i386-20231118.tar.xz
#SITES.${BOOT.nb9-i386}=		${MASTER_SITE_LOCAL:=openjdk21/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-i386}
#EXTRACT_ONLY+=			${BOOT.nb9-i386}
#.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-x86_64
BOOT.nb9-amd64=			bootstrap-jdk-1.21.0.1.12-netbsd-9-amd64-20231119.tar.xz
SITES.${BOOT.nb9-amd64}=	${MASTER_SITE_LOCAL:=openjdk21/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-amd64}
EXTRACT_ONLY+=			${BOOT.nb9-amd64}
.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
#BOOT.nb9-aarch64=		bootstrap-jdk-1.17.0.3.7-netbsd-9-aarch64-20220516.tar.xz
#SITES.${BOOT.nb9-aarch64}=	${MASTER_SITE_LOCAL:=openjdk21/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-aarch64}
#EXTRACT_ONLY+=			${BOOT.nb9-aarch64}
#.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-earmv[67]hf
#BOOT.nb9-earmv6hf=		bootstrap-jdk-1.17.0.3.7-netbsd-9-earmv6hf-20220525.tar.xz
#SITES.${BOOT.nb9-earmv6hf}=	${MASTER_SITE_LOCAL:=openjdk21/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-earmv6hf}
#EXTRACT_ONLY+=			${BOOT.nb9-earmv6hf}
#.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR=		${WRKDIR}/bootstrap
