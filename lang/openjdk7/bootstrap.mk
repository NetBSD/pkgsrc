# $NetBSD: bootstrap.mk,v 1.14 2015/01/09 16:29:04 rumko Exp $

ONLY_FOR_PLATFORM=	NetBSD-[567].*-i386 NetBSD-[567].*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-[23].*-* SunOS-*-* FreeBSD-10.*-x86_64

BOOT.nb5-i386=		bootstrap-jdk7u60-bin-netbsd-5-i386-20140719.tar.bz2
BOOT.nb5-amd64=		bootstrap-jdk7u60-bin-netbsd-5-amd64-20140719.tar.bz2
BOOT.nb6-i386=		bootstrap-jdk7u60-bin-netbsd-6-i386-20140719.tar.bz2
BOOT.nb6-amd64=		bootstrap-jdk7u60-bin-netbsd-6-amd64-20140719.tar.bz2
BOOT.nb7-i386=		bootstrap-jdk7u60-bin-netbsd-7-i386-20140719.tar.bz2
BOOT.nb7-amd64=		bootstrap-jdk7u60-bin-netbsd-7-amd64-20140719.tar.bz2
BOOT.dfly3.6-amd64=	bootstrap-jdk7u60-bin-dragonfly-3.6-amd64-20140719.tar.bz2
BOOT.dfly3.8-amd64=	bootstrap-jdk7u60-bin-dragonfly-3.8-amd64-20140719.tar.bz2
BOOT.fbsd10-amd64=	bootstrap-jdk7u71-bin-freebsd-10-x86_64-20150101.tar.bz2

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb5-i386}
EXTRACT_ONLY+=		${BOOT.nb5-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb5-amd64}
EXTRACT_ONLY+=		${BOOT.nb5-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb6-i386}
EXTRACT_ONLY+=		${BOOT.nb6-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.[0-8]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb6-amd64}
EXTRACT_ONLY+=		${BOOT.nb6-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.99*-i386) || !empty(MACHINE_PLATFORM:MNetBSD-7*-i386) || make(distinfo)
DISTFILES+=		${BOOT.nb7-i386}
EXTRACT_ONLY+=		${BOOT.nb7-i386}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-6.99*-x86_64) || !empty(MACHINE_PLATFORM:MNetBSD-7*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.nb7-amd64}
EXTRACT_ONLY+=		${BOOT.nb7-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.6*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.dfly3.6-amd64}
EXTRACT_ONLY+=		${BOOT.dfly3.6-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MDragonFly-3.[8-9]*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.dfly3.8-amd64}
EXTRACT_ONLY+=		${BOOT.dfly3.8-amd64}
.endif

.if !empty(MACHINE_PLATFORM:MFreeBSD-10.*-x86_64) || make(distinfo)
DISTFILES+=		${BOOT.fbsd10-amd64}
EXTRACT_ONLY+=		${BOOT.fbsd10-amd64}
.endif

.if ${OPSYS} == "SunOS"
BUILDLINK_DEPMETHOD.sun-jdk7?=	build
.include "../../lang/sun-jdk7/buildlink3.mk"
#NB: sun-jdk7 includes sun-jre7/buildlink3.mk
JDK_BOOTDIR=	${BUILDLINK_JAVA_PREFIX.sun-jre7:tA}
MAKE_ENV+=		ALT_JDK_IMPORT_PATH=${JDK_BOOTDIR}
.endif

ALT_BOOTDIR=		${WRKDIR}/bootstrap
