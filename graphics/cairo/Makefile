# $NetBSD: Makefile,v 1.5 2004/02/29 00:06:14 recht Exp $
#

DISTNAME=	cairo-0.1.17
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/snapshots/
COMMENT=	Vector graphics library with cross-device output support

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	cairo.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.5
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1.2
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libpixman/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
