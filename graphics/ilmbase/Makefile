# $NetBSD: Makefile,v 1.3 2008/02/12 16:53:30 rillig Exp $

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

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
