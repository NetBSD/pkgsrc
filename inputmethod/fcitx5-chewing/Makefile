# $NetBSD: Makefile,v 1.21 2026/01/07 08:47:32 wiz Exp $

DISTNAME=	fcitx5-chewing-5.1.1
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-chewing/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-chewing
COMMENT=	Chewing engine for Fcitx5
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
