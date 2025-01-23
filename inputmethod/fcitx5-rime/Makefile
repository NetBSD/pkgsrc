# $NetBSD: Makefile,v 1.6 2025/01/23 23:27:27 riastradh Exp $

DISTNAME=	fcitx5-rime-5.1.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-rime/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-rime
COMMENT=	RIME traditional Chinese input method for Fcitx5
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	rime-luna-pinyin-[0-9]*:../../inputmethod/rime-luna-pinyin

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/librime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
