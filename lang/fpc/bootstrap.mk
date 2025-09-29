# $NetBSD: bootstrap.mk,v 1.1 2025/09/29 14:13:00 ryoon Exp $

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
