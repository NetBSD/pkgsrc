# $NetBSD: Makefile,v 1.22 2021/12/10 13:23:56 nia Exp $

DISTNAME=		luasec-1.0.2
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/^luasec-/sec-/}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=brunoos/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_PROJECT=		${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

DEPENDS+=		${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

BUILD_TARGET.SunOS=	solaris
BUILD_TARGET.*=		bsd

MAKE_ENV+=	LUAPATH=${PREFIX}/${LUA_LDIR}
MAKE_ENV+=	LUACPATH=${PREFIX}/${LUA_CDIR}
MAKE_ENV+=	INC_PATH=-I${PREFIX}/include
MAKE_ENV+=	LIB_PATH="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
MAKE_ENV+=	LD=${CC:Q}

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
