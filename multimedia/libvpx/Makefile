# $NetBSD: Makefile,v 1.46 2014/05/15 11:15:10 martin Exp $

DISTNAME=	libvpx_1.3.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/libv/libvpx/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/webm/
COMMENT=	On2 VP8 library from Google
LICENSE=	modified-bsd

# PR pkg/48508: GCC 4.4 or later is required to compile ssse3 code.
# And It seems that gcc 4.4 and 4.5 do not support OpenBSD/amd64 at least.
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MOpenBSD-*-amd64)
GCC_REQD+=	4.6
.elif ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
GCC_REQD+=	4.4
.endif

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake bash:build perl:build
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	--disable-postproc
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--enable-runtime-cpu-detect
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-unit-tests

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
	${MACHINE_ARCH} == "amd64"
. if ${PKGSRC_COMPILER} == "gcc" && (${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS")
# PR pkg/48508: GCC 4.4 or later is required to compile ssse3 code on NetBSD & Solaris.
GCC_REQD+=	4.4
. endif

BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

REPLACE_BASH=		configure \
			build/make/configure.sh \
			build/make/version.sh \
			build/make/gen_asm_deps.sh \
			build/make/rtcd.sh \
			examples/gen_example_text.sh \
			examples/gen_example_code.sh

REPLACE_PERL=		build/make/ads2gas.pl

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,-Bsymbolic
.  if ${MACHINE_ARCH} == "i386"
.    if !empty(OS_VERSION:M12.*) || !empty(OS_VERSION:M13.*)
CONFIGURE_ARGS+=	--target=x86-darwin12-gcc
.    elif !empty(OS_VERSION:M11.*)
CONFIGURE_ARGS+=	--target=x86-darwin11-gcc
.    elif !empty(OS_VERSION:M10.*)
CONFIGURE_ARGS+=	--target=x86-darwin10-gcc
.    elif !empty(OS_VERSION:M9.*)
CONFIGURE_ARGS+=	--target=x86-darwin9-gcc
.    else
CONFIGURE_ARGS+=	--target=x86-darwin8-gcc
.    endif
.  elif ${MACHINE_ARCH} == "x86_64"
.    if !empty(OS_VERSION:M12.*) || !empty(OS_VERSION:M13.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin12-gcc
.    elif !empty(OS_VERSION:M11.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin11-gcc
.    elif !empty(OS_VERSION:M10.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin10-gcc
.    else
CONFIGURE_ARGS+=	--target=x86_64-darwin9-gcc
.    endif
.  elif ${MACHINE_ARCH} == "powerpc"
.    if !empty(OS_VERSION:M9.*)
CONFIGURE_ARGS+=	--target=ppc32-darwin9-gcc
.    else
CONFIGURE_ARGS+=	--target=ppc32-darwin8-gcc
.    endif
.  endif
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.if ${OPSYS} == "NetBSD"
# https://bugzilla.mozilla.org/show_bug.cgi?id=982693
CFLAGS+=	-fno-integrated-as
.endif
.endif

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "mipsel"
CONFIGURE_ARGS+=	--target=mips32-linux-gcc
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
CONFIGURE_ARGS+=	--disable-runtime-cpu-detect
.endif

.if ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-lrt
# Compiler is too old for these newfangled features
CONFIGURE_ENV+=		sse2=no sse3=no ssse3=no sse4_1=no
# runtime_cpu_detect=no
CONFIGURE_ENV+=		RTCD_OPTIONS='--disable-sse2 --disable-sse3 --disable-ssse3 --disable-sse4_1'
CONFIGURE_ARGS+=	--disable-runtime-cpu-detect
.endif

# Under Solaris 10 its /usr/xpg4/bin/tr is not sufficient. PR pkg/48508
.if !empty(MACHINE_PLATFORM:MSunOS-5.10*)
BUILD_DEPENDS=		coreutils-[0-9]*:../../sysutils/coreutils
FIND_PREFIX:=		GTRDIR=coreutils
.include "../../mk/find-prefix.mk"
TOOLS_PLATFORM.tr=	${GTRDIR}/bin/gtr
.endif

BUILD_TARGET=	# none

post-extract:
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

# PR pkg/48508: newer gas from binutils is required to compile ssse3 code.
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*) || \
	!empty(MACHINE_PLATFORM:MSunOS-5.10*) || \
	!empty(MACHINE_PLATFORM:MOpenBSD-5*)
.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/binutils/override-as.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
