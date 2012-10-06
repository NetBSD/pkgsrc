# $NetBSD: Makefile,v 1.7 2012/10/06 14:11:04 asau Exp $
#

DISTNAME=	libjpeg-turbo-1.2.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://libjpeg-turbo.virtualgl.org/
COMMENT=	libjpeg accelerated with MMX, SSE and SSE2 SIMD instructions
LICENSE=	gnu-lgpl-v2 # OR wxWindows Library Licence, Version 3.1

CONFLICTS=	jpeg-[0-9]*

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

GNU_CONFIGURE=	yes
# compatibility with pkgsrc/graphics/jpeg
CONFIGURE_ARGS+= --with-jpeg8
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
