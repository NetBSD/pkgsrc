# $NetBSD: Makefile,v 1.84 2022/06/28 11:34:57 wiz Exp $

DISTNAME=	x264-snapshot-20191217-2245
PKGNAME=	${DISTNAME:S/-snapshot-/-devel-/:S/-2245$//}
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/x264.html
COMMENT=	GPL licensed H.264 encoder
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

# Assembler code still needs to be disabled on at least SunOS.
# NetBSD/i386 needs ASM disabled to avoid text relocations.
# NetBSD/mips needs ASM disabled because it uses the MSA extension
# (requires MIPS64 revision 2) and fails to build.
.if ${OPSYS} == "SunOS" || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-mips*)
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
MAKE_FLAGS.SunOS+=	INSTALL=${INSTALL}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) || !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
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

.if !empty(USE_BUILTIN.pthread:M[Yy][Ee][Ss])
X264_BUILD_THREADS_SUPPORT=	yes
.else
X264_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
