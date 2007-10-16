# $NetBSD: Makefile,v 1.18 2007/10/16 06:52:43 rillig Exp $

DISTNAME=	openexr-1.4.0a
PKGNAME=	openexr-1.4.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	OpenEXR.pc.in
TEST_TARGET=		check
PTHREAD_OPTS+=		require
LIBS.IRIX+=		-lmx
LIBS.SunOS+=		-lm

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
