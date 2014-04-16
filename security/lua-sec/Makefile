# $NetBSD: Makefile,v 1.10 2014/04/16 14:07:50 fhajny Exp $

DISTNAME=		luasec-0.5
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		https://github.com/brunoos/luasec/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/luasec-${DISTNAME}
INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		solaris
.else
BUILD_TARGET=		bsd
.endif

MAKE_ENV+=	LUAPATH=${PREFIX}/${LUA_LDIR}
MAKE_ENV+=	LUACPATH=${PREFIX}/${LUA_CDIR}
MAKE_ENV+=	INC_PATH=-I${PREFIX}/include
MAKE_ENV+=	LIB_PATH="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
MAKE_ENV+=	LD=${CC:Q}

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
