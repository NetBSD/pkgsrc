# $NetBSD: Makefile,v 1.4 2026/11/27 07:48:27 wiz Exp $

DISTNAME=	luacheck-1.2.0
PKGNAME=	${DISTNAME:S/luacheck/${LUA_PKGPREFIX}-check/}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunarmodules/}
GITHUB_PROJECT=	luacheck
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://luacheck.readthedocs.io/
COMMENT=	Linter and static analyzer for Lua
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-argparse>=0.6.0:../../devel/lua-argparse
DEPENDS+=	${LUA_PKGPREFIX}-filesystem>=1.6.3:../../devel/lua-filesystem
TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted>=0:../../devel/lua-busted
TEST_DEPENDS+=	${LUA_PKGPREFIX}-utf8>=0:../../textproc/lua-utf8

INSTALLATION_DIRS+=	bin ${LUA_LDIR}/luacheck/stages

REPLACE_LUA+=	bin/luacheck.lua

PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/luacheck.lua ${DESTDIR}${PREFIX}/bin/luacheck-${_LUA_DOT_VERSION}
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/stages/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck/stages

# as of 1.2.0
# 458 successes / 1 failure / 0 errors / 1 pending
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} busted${_LUA_DOT_VERSION} -c

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
