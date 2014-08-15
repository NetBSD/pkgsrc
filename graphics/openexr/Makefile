# $NetBSD: Makefile,v 1.34 2014/08/15 18:07:41 richard Exp $

DISTNAME=	openexr-2.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.savannah.nongnu.org/releases/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	OpenEXR.pc.in
TEST_TARGET=		check

GCC_REQD+=	4.3

PTHREAD_OPTS+=		require
LIBS.IRIX+=		-lmx
LIBS.SunOS+=		-lm

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.2nb1
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
