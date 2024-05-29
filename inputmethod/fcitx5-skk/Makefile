# $NetBSD: Makefile,v 1.19 2024/05/29 16:33:09 adam Exp $

DISTNAME=	fcitx5-skk-5.1.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-skk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-skk
COMMENT=	SKK Kana-Kanji inputmethod for fcitx5
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
