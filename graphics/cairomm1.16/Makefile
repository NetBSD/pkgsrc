# $NetBSD: Makefile,v 1.8 2023/11/14 16:01:45 wiz Exp $

DISTNAME=	cairomm-1.18.0
PKGNAME=	${DISTNAME:S/cairomm/cairomm1.16/}
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://cairographics.org/cairomm/
COMMENT=	C++ API for cairo (1.16 API)
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl pkg-config

PKGCONFIG_OVERRIDE+=		output/data/*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

PLIST_VARS+=	x11 quartz

.include "../../devel/libsigc++3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/mm-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.14
.include "../../graphics/cairo/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.cairo:Mx11}
PLIST.x11=	yes
.endif
.if ${PKG_BUILD_OPTIONS.cairo:Mquartz}
PLIST.quartz=	yes
.endif
.include "../../mk/bsd.pkg.mk"
