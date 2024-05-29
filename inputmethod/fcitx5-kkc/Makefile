# $NetBSD: Makefile,v 1.19 2024/05/29 16:33:08 adam Exp $

DISTNAME=	fcitx5-kkc-5.1.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-kkc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-kkc
COMMENT=	libkkc input method support for fcitx5
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

# for std::underlying_type_t
# TODO: check if '8' is correct
GCC_REQD+=	8

DEPENDS+=	skk-jisyo-[0-9]*:../../inputmethod/skk-jisyo
DEPENDS+=	libkkc-data-[0-9]*:../../misc/libkkc-data

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../converters/libkkc/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
