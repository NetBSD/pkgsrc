# $NetBSD: Makefile,v 1.8 2023/11/02 06:36:44 pho Exp $

DISTNAME=	lpeg-1.1.0
DIST_SUBDIR=	${PKGBASE} # To avoid conflicting with devel/lua-lpeg
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing Expression Grammars For Lua
LICENSE=	mit

DEPENDS+=		${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
CONFIGURE_ARGS+=	-f rely-on-shared-lpeg-library

.include "../../lang/hs-lua/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
