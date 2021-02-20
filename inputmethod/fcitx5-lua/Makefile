# $NetBSD: Makefile,v 1.1 2021/02/20 21:36:59 ryoon Exp $

DISTNAME=	fcitx5-lua-5.0.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-lua/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-lua
COMMENT=	Lua support for fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
