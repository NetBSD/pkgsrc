# $NetBSD: Makefile,v 1.7 2024/02/10 12:08:28 ryoon Exp $

DISTNAME=	fcitx5-lua-5.0.12
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-lua/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-lua
COMMENT=	Lua support for fcitx5
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

LUA_VERSIONS_ACCEPTED=	54 53

.include "../../devel/cmake/build.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
