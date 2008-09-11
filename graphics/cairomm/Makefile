# $NetBSD: Makefile,v 1.8 2008/09/11 13:29:58 adam Exp $

DISTNAME=	cairomm-1.6.4
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cairographics.org/cairomm/
COMMENT=	C++ API for cairo

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-docs
PKGCONFIG_OVERRIDE+=	cairomm-1.0.pc.in

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
