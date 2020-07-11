# $NetBSD: Makefile,v 1.3 2020/07/11 14:20:06 nia Exp $

DISTNAME=	lua-compat53-0.9
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=	lua-compat-5.3
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/keplerproject/lua-compat-5.3
COMMENT=	Compatibility module providing Lua-5.3-style APIs for Lua 5.2 and 5.1
LICENSE=	mit

PLIST_SUBST+=	LUA_INCDIR=${LUA_INCDIR}

LDFLAGS.Darwin+=	-undefined dynamic_lookup

PRINT_PLIST_AWK+=	/^${LUA_INCDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_INCDIR:S|/|\\/|g}/, "$${LUA_INCDIR}") }

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR} ${LUA_INCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/compat53
INSTALLATION_DIRS+=	${LUA_CDIR}/compat53

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/*.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/compat53
	${INSTALL_DATA} ${WRKSRC}/compat53/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/compat53
	${INSTALL_DATA} ${WRKSRC}/c-api/* ${DESTDIR}${PREFIX}/${LUA_INCDIR}

do-test:
	cd ${WRKSRC}/tests && ${LUA_INTERPRETER} test.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
