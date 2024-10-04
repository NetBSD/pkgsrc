# $NetBSD: Makefile,v 1.12 2024/10/04 03:49:29 ryoon Exp $

DISTNAME=	fcitx5-table-extra-5.1.3
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-table-extra/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx5/fcitx5-table-extra/
COMMENT=	Extra Chinese table for Fcitx5
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
DEPENDS+=	fcitx5-[0-9]*:../../inputmethod/fcitx5
DEPENDS+=	libime-[0-9]*:../../inputmethod/libime

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
