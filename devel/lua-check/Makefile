# $NetBSD: Makefile,v 1.2 2026/11/26 17:46:00 riastradh Exp $

DISTNAME=	luacheck-0.23.0
PKGNAME=	${DISTNAME:S/luacheck/${LUA_PKGPREFIX}-check/}
PKGREVISION=	1
CATEGORIES=	devel lua

MASTER_SITES=	${MASTER_SITE_GITHUB:=mpeterv/}
GITHUB_PROJECT=	luacheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/mpeterv/luacheck
COMMENT=	Linter and static analyzer for Lua
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-argparse>=0.6.0:../../devel/lua-argparse
DEPENDS+=	${LUA_PKGPREFIX}-filesystem>=1.6.3:../../devel/lua-filesystem

INSTALLATION_DIRS+=	bin ${LUA_LDIR}/luacheck/stages

REPLACE_LUA+=	bin/luacheck.lua

LUA_VERSIONS_INCOMPATIBLE+=	54 55

PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/luacheck.lua ${DESTDIR}${PREFIX}/bin/luacheck-${_LUA_DOT_VERSION}
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/stages/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck/stages

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
