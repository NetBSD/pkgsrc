# $NetBSD: Makefile,v 1.10 2024/05/09 01:32:23 pho Exp $

DISTNAME=	lua-2.3.2
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level bindings to Lua, an embeddable scripting language
LICENSE=	mit

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

# lua.cabal refers to a wrong pkg-config package name. Correct it.
SUBST_CLASSES+=	pc
SUBST_STAGE.pc=	post-extract
SUBST_FILES.pc=	lua.cabal
SUBST_SED.pc=	-E -e 's,(pkgconfig-depends:[[:space:]]*lua)([[:digit:].]+),\1-\2,'

# This package explicitly depends on a specific version of Lua so including
# ../../lang/lua/buildlink3.mk would be inappropriate.
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
