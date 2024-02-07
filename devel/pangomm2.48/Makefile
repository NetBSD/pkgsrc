# $NetBSD: Makefile,v 1.10 2024/02/07 18:19:37 wiz Exp $

DISTNAME=	pangomm-2.50.2
PKGNAME=	${DISTNAME:S/pangomm/pangomm2.48/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangomm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for pango (2.48 API)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 perl:run pkg-config
# TODO: update
PKGCONFIG_OVERRIDE+=	pango/pangomm.pc.in

USE_CXX_FEATURES+=	c++11

.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=      mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.49.4
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm1.16/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
