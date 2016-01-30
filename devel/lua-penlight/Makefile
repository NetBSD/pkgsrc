# $NetBSD: Makefile,v 1.9 2016/01/30 10:52:43 alnsn Exp $
#

DISTNAME=	penlight-${PL_VERSION}
PKGNAME=	${DISTNAME:S/penlight/${LUA_PKGPREFIX}-penlight/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_TAG=	${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://stevedonovan.github.com/Penlight/
COMMENT=	Lua libraries for functional programming, OS path management, etc
LICENSE=	mit

PL_VERSION=	1.3.2
DIST_SUBDIR=	lua-penlight

NO_BUILD=	yes
USE_TOOLS+=	pax

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

WRKSRC=			${WRKDIR}/Penlight-${PL_VERSION}
INSTALLATION_DIRS+=	${LUA_LDIR}

# XXX Generate documentation with Markdown.
do-install:
	cd ${WRKSRC}/lua && find pl ! -type d | \
	    pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
