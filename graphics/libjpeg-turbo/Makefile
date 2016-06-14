# $NetBSD: Makefile,v 1.14 2016/06/14 12:07:57 wiz Exp $

DISTNAME=	libjpeg-turbo-1.5.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://libjpeg-turbo.virtualgl.org/
COMMENT=	Accelerated libjpeg with SIMD instructions
LICENSE=	gnu-lgpl-v2 # OR wxWindows Library Licence, Version 3.1

CONFLICTS=	jpeg-[0-9]*

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

GNU_CONFIGURE=	yes
# compatibility with pkgsrc/graphics/jpeg
CONFIGURE_ARGS+= --with-jpeg8
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	release/libturbojpeg.pc.in release/libjpeg.pc.in

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
