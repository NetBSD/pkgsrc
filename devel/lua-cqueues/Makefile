# $NetBSD: Makefile,v 1.11 2026/01/11 07:45:43 wiz Exp $

DISTNAME=	cqueues-20200726
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=wahern/}
GITHUB_PROJECT=	cqueues
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://25thandclement.com/~william/projects/cqueues.html
COMMENT=	Stackable Continuation Queues for Lua
LICENSE=	mit

USE_TOOLS+=	gmake m4

MAKE_ENV+=	prefix=${PREFIX}

BUILD_TARGET=	all${_LUA_DOT_VERSION}
INSTALL_TARGET=	install${_LUA_DOT_VERSION}

MAKE_FLAGS+=	LUA_APIS=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

# does not support lua 5.5 as of 20200726
LUA_VERSIONS_ACCEPTED=	54 53 52 51

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
