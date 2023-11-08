# $NetBSD: Makefile,v 1.25 2023/11/08 11:16:56 nia Exp $

DISTNAME=	luaposix-35.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=luaposix/}
GITHUB_PROJECT=	luaposix
GITHUB_TAG=	v${PKGVERSION_NOREV}

kAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luaposix/luaposix
COMMENT=	POSIX library for Lua language
LICENSE=	mit

USE_LANGUAGES=	c99
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-std-normalize-[0-9]*:../../devel/lua-std-normalize
DEPENDS+=	${LUA_PKGPREFIX}-std-_debug-[0-9]*:../../devel/lua-std-_debug
.if ${LUA_PKGPREFIX} == "lua51"
DEPENDS+=	lua51-bit32-[0-9]*:../../devel/lua-bit32
.endif

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} != "Darwin"
LIBFLAG+=	${LDFLAGS} -shared -fPIC
.else
LIBFLAG+=	${LDFLAGS} -fPIC
.endif

do-build:
	cd ${WRKSRC} && \
		env ${MAKE_ENV} \
		${LUA_INTERPRETER} ./build-aux/luke LIBFLAG=${LIBFLAG:Q}

do-install:
	cd ${WRKSRC} && \
		env ${MAKE_ENV} \
		${LUA_INTERPRETER} ./build-aux/luke \
			PREFIX=${DESTDIR}${PREFIX} \
			install
	cd ${WRKSRC}/doc && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
