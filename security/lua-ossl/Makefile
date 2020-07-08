# $NetBSD: Makefile,v 1.1 2020/07/08 12:41:12 nia Exp $

DISTNAME=	luaossl-20190731
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=wahern/}
CATEGORIES=	security lua
GITHUB_PROJECT=	luaossl
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://25thandclement.com/~william/projects/luaossl.html
COMMENT=	Comprehensive OpenSSL module for Lua
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile

BUILD_DIRS=	src

MAKE_ENV+=	prefix=${PREFIX}

BUILD_TARGET=	all${_LUA_DOT_VERSION}
INSTALL_TARGET=	install${_LUA_DOT_VERSION}

MAKE_FLAGS+=	LUA_APIS=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

LUA_VERSIONS_ACCEPTED=	53 52 51

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
