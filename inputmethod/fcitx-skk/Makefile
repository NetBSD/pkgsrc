# $NetBSD: Makefile,v 1.12 2020/11/05 09:08:30 ryoon Exp $

DISTNAME=	fcitx-skk-0.1.4
PKGREVISION=	10
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-skk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx-skk/
COMMENT=	SKK module for Fcitx
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/fcitx-qt5/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
