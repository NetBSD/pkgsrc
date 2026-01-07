# $NetBSD: Makefile,v 1.28 2026/01/07 08:47:32 wiz Exp $

DISTNAME=	fcitx5-kkc-5.1.1
PKGREVISION=	9
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-kkc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-kkc
COMMENT=	libkkc input method support for fcitx5
LICENSE=	gnu-gpl-v3

# for std::underlying_type_t
# TODO: check if '8' is correct
GCC_REQD+=	8

DEPENDS+=	skk-jisyo-[0-9]*:../../inputmethod/skk-jisyo
DEPENDS+=	libkkc-data-[0-9]*:../../misc/libkkc-data

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"

.include "../../converters/libkkc/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
