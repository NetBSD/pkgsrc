# $NetBSD: Makefile,v 1.3 2022/02/26 03:58:15 pho Exp $

DISTNAME=	lua-2.1.0
PKGREVISION=	2
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level bindings to Lua, an embeddable scripting language
LICENSE=	mit

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

# This package explicitly depends on Lua 5.3.x so including
# ../../lang/lua/buildlink3.mk would be inappropriate.
.include "../../lang/lua53/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
