# $NetBSD: Makefile,v 1.7 2022/11/23 16:25:53 adam Exp $

DISTNAME=	lua-zlib-1.2
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	archivers lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=brimworks/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	lua-zlib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brimworks/lua-zlib
COMMENT=	Simple streaming interface to zlib for Lua
LICENSE=	mit

BUILD_TARGET=	zlib.so

MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	LD=${CC}
MAKE_FLAGS+=	CFLAGS="${CFLAGS} -fPIC"
MAKE_FLAGS+=	LDFLAGS="${LDFLAGS} -shared"

INSTALLATION_DIRS+=	${LUA_CDIR}

# Links against unversioned base Lua on NetBSD...
BUILDLINK_TRANSFORM+=	rm:-llua

BUILDLINK_TRANSFORM.Darwin+=	rm:-bundle

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/zlib.so ${DESTDIR}${PREFIX}/${LUA_CDIR}
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/${LUA_CDIR}/zlib.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/zlib.so
.endif

.include "../../lang/lua/module.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
