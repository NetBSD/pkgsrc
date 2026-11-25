# $NetBSD: Makefile,v 1.71 2026/11/25 14:42:12 wiz Exp $

DISTNAME=	glu-9.0.3
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/glu/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/mesa/glu
COMMENT=	OpenGL Utility Library
LICENSE=	sgi-free-software-b-v2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/glu.pc

.include "../../devel/meson/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
