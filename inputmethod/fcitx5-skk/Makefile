# $NetBSD: Makefile,v 1.28 2026/01/07 08:47:33 wiz Exp $

DISTNAME=	fcitx5-skk-5.1.1
PKGREVISION=	9
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-skk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-skk
COMMENT=	SKK Kana-Kanji inputmethod for fcitx5
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
