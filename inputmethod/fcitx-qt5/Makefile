# $NetBSD: Makefile,v 1.37 2026/01/07 08:47:32 wiz Exp $

DISTNAME=	fcitx-qt5-1.2.3
PKGREVISION=	32
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

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
