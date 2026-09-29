# $NetBSD: bootstrap.mk,v 1.5 2026/09/29 10:49:57 tnn Exp $

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
BOOT.nb9-aarch64=		bootstrap-jdk-1.21.0.7.6-netbsd-9-aarch64-20250811.tar.xz
SITES.${BOOT.nb9-aarch64}=	${MASTER_SITE_LOCAL:=openjdk21/}
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.nb9-aarch64}
EXTRACT_ONLY+=			${BOOT.nb9-aarch64}
.endif

#ONLY_FOR_PLATFORM+=		NetBSD-*-earmv[67]hf
#BOOT.nb9-earmv6hf=		bootstrap-jdk-1.17.0.3.7-netbsd-9-earmv6hf-20220525.tar.xz
#SITES.${BOOT.nb9-earmv6hf}=	${MASTER_SITE_LOCAL:=openjdk21/}
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf) || make(distinfo)
#DISTFILES+=			${BOOT.nb9-earmv6hf}
#EXTRACT_ONLY+=			${BOOT.nb9-earmv6hf}
#.endif

ONLY_FOR_PLATFORM+=		Linux-*-x86_64
BOOT.linux-amd64=		OpenJDK21U-jdk_x64_linux_hotspot_21.0.9_10.tar.gz
SITES.${BOOT.linux-amd64}=	https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.9%2B10/
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.linux-amd64}
EXTRACT_ONLY+=			${BOOT.linux-amd64}
ALT_BOOTDIR=			${WRKDIR}/jdk-21.0.9+10
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-aarch64
BOOT.darwin-aarch64+=		OpenJDK21U-jdk_aarch64_mac_hotspot_21.0.9_10.tar.gz
SITES.${BOOT.darwin-aarch64}=	https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.9%2B10/
.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.darwin-aarch64}
EXTRACT_ONLY+=			${BOOT.darwin-aarch64}
ALT_BOOTDIR=			${WRKDIR}/jdk-21.0.9+10/Contents/Home
.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR?=		${WRKDIR}/bootstrap
