# $NetBSD: Makefile,v 1.1 2021/02/17 15:23:49 ryoon Exp $

DISTNAME=	fcitx5-qt-5.0.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx5/fcitx5-qt/
COMMENT=	Qt5 library and IM module for fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DENABLE_QT4=off
CMAKE_ARGS+=		-DENABLE_QT6=off

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
