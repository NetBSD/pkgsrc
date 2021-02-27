# $NetBSD: Makefile,v 1.2 2021/02/27 19:37:31 ryoon Exp $

DISTNAME=	fcitx5-qt-5.0.3
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
