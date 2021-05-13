# $NetBSD: Makefile,v 1.18 2021/05/13 10:19:09 nia Exp $
#

DISTNAME=	penlight-1.10.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunarmodules/}
GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	Penlight

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stevedonovan.github.com/Penlight/
COMMENT=	Lua libraries for functional programming, OS path management, etc
LICENSE=	mit

DIST_SUBDIR=	lua-penlight

NO_BUILD=	yes
USE_TOOLS+=	pax

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

WRKSRC=			${WRKDIR}/Penlight-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	${LUA_LDIR}

# XXX Generate documentation with Markdown.
do-install:
	cd ${WRKSRC}/lua && find pl ! -type d | \
	    pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}

do-test:
	cd ${WRKSRC} && ${LUA_INTERPRETER} run.lua tests

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
