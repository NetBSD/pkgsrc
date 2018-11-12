# $NetBSD: Makefile,v 1.2 2018/11/12 03:52:21 ryoon Exp $

DISTNAME=	fcitx-qt5-1.2.3
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-qt5/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx-qt5/
COMMENT=	Fcitx Qt5 Input Context
LICENSE=	gnu-gpl-v2 OR modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
