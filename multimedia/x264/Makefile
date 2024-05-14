# $NetBSD: Makefile,v 1.4 2024/05/14 17:39:14 jperkin Exp $

# Download https://code.videolan.org/videolan/x264/-/archive/stable/x264-stable.tar.bz2
# Rename to x264-<last-commit-date>.tar.bz2 and upload to MASTER_SITE_LOCAL.

DISTNAME=	x264-20231001
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/x264.html
COMMENT=	GPL licensed H.264 encoder
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/x264-stable

CONFLICTS+=	x264-devel-[0-9]*
SUPERSEDES+=	x264-devel-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Assembler code still needs to be disabled on at least SunOS.
# NetBSD/i386 needs ASM disabled to avoid text relocations.
# NetBSD/mips needs ASM disabled because it uses the MSA extension
# Darwin/powerpc needs ASM disabled; it needs Altivec and build fails on G4.
# (requires MIPS64 revision 2) and fails to build.
.if ${OPSYS} == "SunOS" || \
    ${MACHINE_PLATFORM:MNetBSD-*-i386} || \
    ${MACHINE_PLATFORM:MNetBSD-*-mips*} || \
    ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
CONFIGURE_ARGS+=	--disable-asm
.elif ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    (${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "aarch64")
TOOL_DEPENDS+=		nasm>=2.13.0:../../devel/nasm
.endif

USE_TOOLS+=		bash gmake
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.if ${OPSYS} == "Darwin"
USE_TOOLS+=		perl
.else
CONFIGURE_ARGS+=	--disable-opencl
.endif
MAKE_ENV+=		SH=${SH:Q}

# tries to use /usr/ucb/install to create multiple directories
# PR pkg/56512
MAKE_FLAGS.SunOS+=	INSTALL=${INSTALL:Q}

.if ${USE_CROSS_COMPILE:U:tl} == yes || ${MACHINE_PLATFORM:MDarwin-*-aarch64}
# XXX Consider passing this whether cross-compiling or not.
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif

BUILD_TARGET=		default
INSTALL_TARGET=		install-lib-shared install-lib-static install-cli
INSTALLATION_DIRS=	bin
REPLACE_SH=		version.sh

.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

.if ${USE_BUILTIN.pthread:tl} == yes
X264_BUILD_THREADS_SUPPORT=	yes
.else
X264_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
