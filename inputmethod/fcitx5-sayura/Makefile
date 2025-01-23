# $NetBSD: Makefile,v 1.7 2025/01/23 23:27:28 riastradh Exp $

DISTNAME=	fcitx5-sayura-5.1.1
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-sayura/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-sayura
COMMENT=	Sinhala input method for Fcitx5
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
