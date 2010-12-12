# $NetBSD: Makefile,v 1.3 2010/12/12 13:37:48 wiz Exp $
#

DISTNAME=	libjpeg-turbo-1.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://libjpeg-turbo.virtualgl.org/
COMMENT=	libjpeg accelerated with MMX, SSE and SSE2 SIMD instructions
LICENSE=	gnu-lgpl-v2 # OR wxWindows Library Licence, Version 3.1

CONFLICTS=	jpeg-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
