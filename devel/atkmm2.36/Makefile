# $NetBSD: Makefile,v 1.6 2024/10/20 14:03:33 wiz Exp $

DISTNAME=	atkmm-2.36.3
PKGNAME=	${DISTNAME:S/atkmm/atkmm2.36/}
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for atk (2.36 API)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=		c c++17
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=		output/atk/atkmm-2.36.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
