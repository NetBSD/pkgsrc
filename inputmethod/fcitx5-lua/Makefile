# $NetBSD: Makefile,v 1.5 2021/03/29 08:45:48 nia Exp $

DISTNAME=	fcitx5-lua-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-lua/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-lua
COMMENT=	Lua support for fcitx5
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

LUA_VERSIONS_ACCEPTED=	54 53

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
