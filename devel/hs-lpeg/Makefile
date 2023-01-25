# $NetBSD: Makefile,v 1.4 2023/01/25 04:30:49 pho Exp $

DISTNAME=	lpeg-1.0.3
DIST_SUBDIR=	${PKGBASE} # To avoid conflicting with devel/lua-lpeg
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
