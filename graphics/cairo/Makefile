# $NetBSD: Makefile,v 1.1.1.1 2004/02/03 12:16:42 recht Exp $
#

DISTNAME=	cairo-0.1.17
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/snapshots/
COMMENT=	Vector graphics library with cross-device output support

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/cairo.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.freetype2=  freetype2>=2.1.5
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/libpixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
