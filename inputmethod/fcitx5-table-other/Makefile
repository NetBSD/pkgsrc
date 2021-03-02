# $NetBSD: Makefile,v 1.2 2021/03/02 13:24:54 ryoon Exp $

DISTNAME=	fcitx5-table-other-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-table-other/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx5/fcitx5-table-other/
COMMENT=	Non-Chinese tables for Fcitx5
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

DEPENDS+=	fcitx5-[0-9]*:../../inputmethod/fcitx5
DEPENDS+=	libime-[0-9]*:../../inputmethod/libime

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
