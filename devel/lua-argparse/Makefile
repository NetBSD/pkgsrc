# $NetBSD: Makefile,v 1.1 2020/07/02 11:36:36 nia Exp $

DISTNAME=	lua-argparse-0.7.0
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=luarocks/}
GITHUB_PROJECT=	argparse

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luarocks/argparse
COMMENT=	Feature-rich command-line argument parser for Lua
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/lua-//}

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
