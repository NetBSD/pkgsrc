# $NetBSD: Makefile,v 1.8 2025/01/23 23:27:26 riastradh Exp $

DISTNAME=	fcitx5-anthy-5.1.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-anthy/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-anthy
COMMENT=	Anthy Japanese inputmethod for Fcitx5
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
