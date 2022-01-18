# $NetBSD: Makefile,v 1.4 2022/01/18 02:48:17 pho Exp $

DISTNAME=	hslua-1.3.0.1
PKGREVISION=	2
CATEGORIES=	lang

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Bindings to Lua, an embeddable scripting language
LICENSE=	mit

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

# This package explicitly depends on Lua 5.3.x so including
# ../../lang/lua/buildlink3.mk would be inappropriate.
.include "../../lang/lua53/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
