# $NetBSD: Makefile,v 1.1 2021/02/20 21:17:14 ryoon Exp $

DISTNAME=	fcitx5-rime-5.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-rime/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-rime
COMMENT=	RIME traditional Chinese input method for Fcitx5
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	rime-luna-pinyin-[0-9]*:../../inputmethod/rime-luna-pinyin

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/librime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
