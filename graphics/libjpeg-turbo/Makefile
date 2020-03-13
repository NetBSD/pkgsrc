# $NetBSD: Makefile,v 1.18 2020/03/13 17:55:33 tnn Exp $

DISTNAME=	libjpeg-turbo-1.5.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://libjpeg-turbo.virtualgl.org/
COMMENT=	Accelerated libjpeg with SIMD instructions
LICENSE=	gnu-lgpl-v2 # OR wxWindows Library Licence, Version 3.1

# Note also that libjpeg-turbo's library has a different major version
# number (8) than that installed by the jpeg package (9).
#   https://libjpeg-turbo.org/About/Jpeg-9
CONFLICTS=	jpeg-[0-9]*

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

GNU_CONFIGURE=		yes
# Ask for compatibility with jpeg 8, to get the highest ABI that
# libjpeg-turbo supports.
CONFIGURE_ARGS+=	--with-jpeg8
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

CHECK_PORTABILITY_SKIP+=	release/makemacpkg.in
PKGCONFIG_OVERRIDE=	release/libturbojpeg.pc.in release/libjpeg.pc.in

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
