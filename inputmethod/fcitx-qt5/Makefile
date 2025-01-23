# $NetBSD: Makefile,v 1.32 2025/01/23 23:27:26 riastradh Exp $

DISTNAME=	fcitx-qt5-1.2.3
PKGREVISION=	28
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
