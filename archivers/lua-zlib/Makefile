# $NetBSD: Makefile,v 1.1 2020/07/02 20:00:23 nia Exp $

DISTNAME=	lua-zlib-1.2
CATEGORIES=	archivers lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=brimworks/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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

do-install:
	${INSTALL_LIB} ${WRKSRC}/zlib.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
