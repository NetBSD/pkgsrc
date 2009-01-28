# $NetBSD: Makefile,v 1.4 2009/01/28 13:14:54 tron Exp $

DISTNAME=	ilmbase-1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
LIBS.SunOS=		-lm

PKGCONFIG_OVERRIDE=	IlmBase.pc.in
PTHREAD_OPTS=		require

CONFLICTS=		openexr<1.6

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
