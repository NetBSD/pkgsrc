# $NetBSD: Makefile,v 1.1 2017/08/14 21:11:09 triaxx Exp $

DISTNAME=	ldoc-1.4.6
PKGNAME=	${DISTNAME:S/l/${LUA_PKGPREFIX}-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_PROJECT=	ldoc

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://stevedonovan.github.io/ldoc/
COMMENT=	LuaDoc-compatible documentation generation system
LICENSE=	mit

MAKE_FLAGS+=	LUA=${LUA_INTERPRETER}
MAKE_FLAGS+=	LUA_BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	LUA_SHAREDIR=${PREFIX}/${LUA_LDIR}
MAKE_FILE=	makefile
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/LDoc-${PKGVERSION_NOREV}

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight

.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
