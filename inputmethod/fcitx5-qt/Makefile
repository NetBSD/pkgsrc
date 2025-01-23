# $NetBSD: Makefile,v 1.24 2025/01/23 23:27:27 riastradh Exp $

DISTNAME=	fcitx5-qt-5.1.4
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
COMMENT=	Qt library and IM module for fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=		-DENABLE_QT4=off
CMAKE_CONFIGURE_ARGS+=		-DENABLE_QT5=on
CMAKE_CONFIGURE_ARGS+=		-DENABLE_QT6=off

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
