# $NetBSD: Makefile,v 1.3 2013/07/14 20:28:19 alnsn Exp $
#

DISTNAME=	${PL_VERSION}
PKGNAME=	lua-penlight-${PL_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/stevedonovan/Penlight/archive/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/stevedonovan/Penlight/archive/
COMMENT=	Lua libraries for functional programming, OS path management, etc
LICENSE=	mit

PL_VERSION=	1.1.1
DIST_SUBDIR=	lua-penlight

NO_BUILD=	yes
USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}/Penlight-${PL_VERSION}
INSTALLATION_DIRS+=	${LUA_LDIR}

# XXX Generate documentation with Markdown.
do-install:
	cd ${WRKSRC}/lua && find pl ! -type d | \
	    pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
