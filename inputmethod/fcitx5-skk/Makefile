# $NetBSD: Makefile,v 1.2 2021/02/27 20:10:32 ryoon Exp $

DISTNAME=	fcitx5-skk-5.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-skk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-skk
COMMENT=	SKK Kana-Kanji inputmethod for fcitx5
LICENSE=	gnu-gpl-v3

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
