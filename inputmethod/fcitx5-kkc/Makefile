# $NetBSD: Makefile,v 1.1 2021/03/06 04:26:23 ryoon Exp $

DISTNAME=	fcitx5-kkc-5.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-kkc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-kkc
COMMENT=	libkkc input method support for fcitx5
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

DEPENDS+=	skk-jisyo-[0-9]*:../../inputmethod/skk-jisyo
DEPENDS+=	libkkc-data-[0-9]*:../../misc/libkkc-data

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../converters/libkkc/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
