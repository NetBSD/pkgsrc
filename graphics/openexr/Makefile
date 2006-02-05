# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:36 joerg Exp $

DISTNAME=	OpenEXR-1.2.2
PKGNAME=	openexr-1.2.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/OpenExr.pc.in
TEST_TARGET=		check

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
