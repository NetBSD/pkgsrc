# $NetBSD: Makefile,v 1.34 2025/04/24 14:14:46 wiz Exp $

DISTNAME=	fcitx-qt5-1.2.3
PKGREVISION=	30
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-qt5/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx-qt5/
COMMENT=	Fcitx Qt5 Input Context
LICENSE=	gnu-gpl-v2 OR modified-bsd

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

LDFLAGS+=	-lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
