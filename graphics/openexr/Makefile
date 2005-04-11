# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:07 tv Exp $

DISTNAME=	OpenEXR-1.2.2
PKGNAME=	openexr-1.2.2
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes # for exrdisplay FLTK application
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/OpenExr.pc.in
TEST_TARGET=		check

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
