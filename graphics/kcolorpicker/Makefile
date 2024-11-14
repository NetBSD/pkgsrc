# $NetBSD: Makefile,v 1.15 2024/11/14 22:20:10 wiz Exp $

DISTNAME=	kcolorpicker-0.3.1
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksnip/}
GITHUB_PROJECT=	kColorPicker
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DamirPorobic/kColorPicker/
COMMENT=	Qt based Color Picker with popup menu
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
