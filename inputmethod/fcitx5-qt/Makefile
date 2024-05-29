# $NetBSD: Makefile,v 1.19 2024/05/29 16:33:09 adam Exp $

DISTNAME=	fcitx5-qt-5.1.4
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
COMMENT=	Qt library and IM module for fcitx5
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DENABLE_QT4=off
CMAKE_ARGS+=		-DENABLE_QT5=on
CMAKE_ARGS+=		-DENABLE_QT6=off

.include "../../devel/cmake/build.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
