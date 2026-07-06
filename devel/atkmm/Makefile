# $NetBSD: Makefile,v 1.39 2026/07/06 12:07:51 adam Exp $

DISTNAME=	atkmm-2.28.5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for atk (1.6 API)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

CONFLICTS+=	gtkmm<2.22.0

USE_LANGUAGES=		c c++11
USE_TOOLS+=		perl pkg-config
PKGCONFIG_OVERRIDE+=	atk/atkmm.pc.in

MESON_REQD+=	0.60.0

BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
