# $NetBSD: Makefile,v 1.6 2023/05/22 21:00:31 wiz Exp $

DISTNAME=	kcolorpicker-0.2.0
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksnip/}
GITHUB_PROJECT=	kColorPicker
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DamirPorobic/kColorPicker/
COMMENT=	Qt based Color Picker with popup menu
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
