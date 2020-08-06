# $NetBSD: Makefile,v 1.1 2020/08/06 23:08:29 joerg Exp $

DISTNAME=	repl-0.9
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoelzro/}
GITHUB_PROJECT=	lua-repl
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoelzro/lua-linenoise/
COMMENT=	REPL library for Lua
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin ${LUA_LDIR}/repl/plugins

PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

REPLACE_LUA+=	rep.lua

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rep.lua ${DESTDIR}${PREFIX}/bin/luarep-${_LUA_DOT_VERSION}
	${INSTALL_DATA} ${WRKSRC}/repl/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/repl
	${INSTALL_DATA} ${WRKSRC}/repl/plugins/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/repl/plugins

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
