# $NetBSD: Makefile,v 1.1.1.1 2005/01/17 13:20:11 adam Exp $

DISTNAME=	OpenEXR-1.2.1
PKGNAME=	openexr-1.2.1
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/OpenExr.pc.in

.include "../../x11/fltk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
