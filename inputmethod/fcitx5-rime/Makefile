# $NetBSD: Makefile,v 1.5 2024/02/10 12:14:03 ryoon Exp $

DISTNAME=	fcitx5-rime-5.1.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-rime/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-rime
COMMENT=	RIME traditional Chinese input method for Fcitx5
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
DEPENDS+=	rime-luna-pinyin-[0-9]*:../../inputmethod/rime-luna-pinyin

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/librime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
