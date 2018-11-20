# $NetBSD: Makefile,v 1.16 2018/11/20 17:30:47 maya Exp $

DISTNAME=	luaposix-34.0.4
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=luaposix/}
GITHUB_PROJECT=	luaposix
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luaposix/luaposix
COMMENT=	POSIX library for Lua language
LICENSE=	mit

USE_LANGUAGES=	c c99

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-std-normalize-[0-9]*:../../devel/lua-std-normalize
DEPENDS+=	${LUA_PKGPREFIX}-std-_debug-[0-9]*:../../devel/lua-std-_debug
.if ${LUA_PKGPREFIX} == "lua51"
DEPENDS+=	lua51-bitlib-[0-9]*:../../devel/lua-bitlib
.endif

LIBFLAG+=	${LDFLAGS} -shared -fPIC

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

.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
