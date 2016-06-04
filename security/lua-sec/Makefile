# $NetBSD: Makefile,v 1.15 2016/06/04 21:48:11 alnsn Exp $

DISTNAME=		luasec-0.6
PKGNAME=		${DISTNAME:S/luasec/${LUA_PKGPREFIX}-sec/}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=brunoos/}
GITHUB_TAG=		${DISTNAME}
GITHUB_PROJECT=		${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

DEPENDS+=		${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/luasec-${DISTNAME}
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
