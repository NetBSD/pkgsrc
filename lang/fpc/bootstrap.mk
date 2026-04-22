# $NetBSD: bootstrap.mk,v 1.2 2026/04/22 23:17:35 js Exp $

ONLY_FOR_PLATFORM+=		NetBSD-*-i386
BOOT.nb-i386=			fpc-3.2.2.i386-netbsd.tar
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.nb-i386}
EXTRACT_ONLY+=			${BOOT.nb-i386}
COMPILER=			ppc386
MAKE_ENV+=			-Damd64=0 -Di386=1
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-x86_64
BOOT.nb-amd64=			fpc-3.2.2.x86_64-netbsd.tar
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.nb-amd64}
EXTRACT_ONLY+=			${BOOT.nb-amd64}
COMPILER=			ppcx64
MAKE_ENV+=			-Damd64=1 -Di386=0
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-aarch64
BOOT.darwin-arm64=		fpc-3.2.2.intelarm64-macosx.dmg
.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64) || make(distinfo)
DISTFILES+=			${BOOT.darwin-arm64}
EXTRACT_ONLY+=			${BOOT.darwin-arm64}
COMPILER=			ppca64
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-i386
BOOT.darwin-i386=		fpc-3.2.2.intelarm64-macosx.dmg
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo)
DISTFILES+=			${BOOT.darwin-i386}
EXTRACT_ONLY+=			${BOOT.darwin-i386}
COMPILER=			ppc386
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-powerpc
BOOT.darwin-ppc=		fpc-3.2.2.powerpc-macosx.dmg
.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc) || make(distinfo)
DISTFILES+=			${BOOT.darwin-ppc}
EXTRACT_ONLY+=			${BOOT.darwin-ppc}
COMPILER=			ppcppc
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-powerpc64
BOOT.darwin-ppc64=		fpc-3.2.2.powerpc-macosx.dmg
.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc64) || make(distinfo)
DISTFILES+=			${BOOT.darwin-ppc64}
EXTRACT_ONLY+=			${BOOT.darwin-ppc64}
COMPILER=			ppcppc64
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-x86_64
BOOT.darwin-amd64=		fpc-3.2.2.intelarm64-macosx.dmg
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.darwin-amd64}
EXTRACT_ONLY+=			${BOOT.darwin-amd64}
COMPILER=			ppcx64
.endif

# I added the infrastructure to bootstrap on macOS and it does compile, but
# linking fails with it not finding -lc and I could not figure out yet why.
#   -- js@
BROKEN_ON_PLATFORM+=		Darwin-*-*
