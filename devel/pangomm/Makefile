# $NetBSD: Makefile,v 1.73 2023/11/14 14:01:39 wiz Exp $

DISTNAME=	pangomm-2.46.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangomm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for pango (1.4 API)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	gtkmm<=2.13.5

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 perl:run pkg-config
PKGCONFIG_OVERRIDE+=	pango/pangomm.pc.in

USE_CXX_FEATURES+=	c++11

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=      mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.48.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.14.0
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
