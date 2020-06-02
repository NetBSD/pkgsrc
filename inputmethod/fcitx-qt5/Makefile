# $NetBSD: Makefile,v 1.12 2020/06/02 08:24:09 adam Exp $

DISTNAME=	fcitx-qt5-1.2.3
PKGREVISION=	10
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-qt5/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx-qt5/
COMMENT=	Fcitx Qt5 Input Context
LICENSE=	gnu-gpl-v2 OR modified-bsd

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

LDFLAGS+=	-lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
