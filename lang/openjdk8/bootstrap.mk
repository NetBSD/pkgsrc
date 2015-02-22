# $NetBSD: bootstrap.mk,v 1.4 2015/02/22 08:40:07 tnn Exp $
#
# This file contains a map of available binary bootstrap toolchains
# and which kit to use for each supported platform.
#
# Instructions for regenerating a bootstrap kit:
#  1) Prepare a new chroot environment in which to build the kit
#  2) If the running kernel version is not a release, use pkgtools/libkver
#  3) Disable the x11 PKG_OPTION in openjdk7
#  4) "make"
#  5) cd $(make show-var VARNAME=BUILDDIR)
#  6) mv j2sdk-image bootstrap
#  7) cd bootstrap; rm -r demo man release sample src.zip
#  8) When preparing kits for NetBSD 7 and above with gcc, copy libgcc_s.so.*
#     and libstdc++.so.* from base to bootstrap/jre/lib/${LIBDIR_ARCH}.
#     This will ensure that MKLLVM=yes/MKGCC=no user in the future can run
#     the bootstrap toolchain.
#  9) tar cf - bootstrap | xz -9c > bootstrap-xxx.tar.xz
# 10) gpg --sign -a bootstrap-xxx.tar.xz
# 11) Upload archive and signature to ${MASTER_SITE_LOCAL:=openjdk7/}
#
# All binary kits from now on MUST have an accompanying PGP signature from
# the person who prepared the kit. Unsigned binaries on ftp will be purged.
#
# Initial bootstrapping on a previously non-supported architecture
# is not trivial to do with openjdk7. It is somewhat easier with openjdk8
# which has improved cross-compile support. Note that openjdk8 cannot be used
# for bootstrapping openjdk7 out of the box. (It is possible with hacks.)

ONLY_FOR_PLATFORM=	NetBSD-[567].*-i386 NetBSD-[567].*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-7.*-sparc64
ONLY_FOR_PLATFORM+=	DragonFly-[23].*-* SunOS-*-* FreeBSD-10.*-x86_64

BOOT.nb5-i386=		bootstrap-jdk7u60-bin-netbsd-5-i386-20140719.tar.bz2
BOOT.nb5-amd64=		bootstrap-jdk7u60-bin-netbsd-5-amd64-20140719.tar.bz2
BOOT.nb6-i386=		bootstrap-jdk7u60-bin-netbsd-6-i386-20140719.tar.bz2
BOOT.nb6-amd64=		bootstrap-jdk7u60-bin-netbsd-6-amd64-20140719.tar.bz2
BOOT.nb7-i386=		bootstrap-jdk7u60-bin-netbsd-7-i386-20140719.tar.bz2
BOOT.nb7-amd64=		bootstrap-jdk7u60-bin-netbsd-7-amd64-20140719.tar.bz2
BOOT.nb7-sparc64=	bootstrap-jdk7u76-bin-netbsd-7-sparc64-20150212.tar.xz
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

.if !empty(MACHINE_PLATFORM:MNetBSD-7*-sparc64) || make(distinfo)
DISTFILES+=		${BOOT.nb7-sparc64}
EXTRACT_ONLY+=		${BOOT.nb7-sparc64}
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
JDK_BOOTDIR=		${BUILDLINK_JAVA_PREFIX.sun-jre7:tA}
CONFIGURE_ARGS+=	--with-import-hotspot=${JDK_BOOTDIR}
.endif

ALT_BOOTDIR=		${WRKDIR}/bootstrap
