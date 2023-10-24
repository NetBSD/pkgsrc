# $NetBSD: Makefile,v 1.4 2023/10/24 22:10:52 wiz Exp $

DISTNAME=	luaossl-20220711
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
PKGREVISION=	1
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

LUA_VERSIONS_ACCEPTED=	54 53 52 51

INSTALLATION_DIRS+=	${LUA_DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
