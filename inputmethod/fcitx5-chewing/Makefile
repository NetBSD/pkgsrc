# $NetBSD: Makefile,v 1.14 2024/05/29 16:33:08 adam Exp $

DISTNAME=	fcitx5-chewing-5.1.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-chewing/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-chewing
COMMENT=	Chewing engine for Fcitx5
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
