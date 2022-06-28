# $NetBSD: Makefile,v 1.5 2022/06/28 11:33:41 wiz Exp $

DISTNAME=	pangomm-2.48.2
PKGNAME=	${DISTNAME:S/pangomm/pangomm2.48/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangomm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for pango (2.48 API)
LICENSE=	gnu-lgpl-v2.1

GCC_REQD+=		4.9
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 perl:run pkg-config
# TODO: update
PKGCONFIG_OVERRIDE+=	pango/pangomm.pc.in

.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=      mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.48.0
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm1.16/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
