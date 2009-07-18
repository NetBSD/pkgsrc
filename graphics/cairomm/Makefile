# $NetBSD: Makefile,v 1.10 2009/07/18 13:06:44 wiz Exp $

DISTNAME=	cairomm-1.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cairographics.org/cairomm/
COMMENT=	C++ API for cairo
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-docs
PKGCONFIG_OVERRIDE+=	cairomm-1.0.pc.in

.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
