# $NetBSD: Makefile,v 1.2 2023/10/24 22:08:27 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${LUA_PKGPREFIX}-${GITHUB_PROJECT:S/lua//}-1.3.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=lualdap/}
GITHUB_PROJECT=	lualdap
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lualdap.github.io/lualdap/
COMMENT=	Simple interface from Lua to an LDAP client
LICENSE=	modified-bsd

LUA_VERSIONS_ACCEPTED=	54 53 52 51

USE_LANGUAGES=	c
USE_TOOLS=	gmake

BUILD_TARGET=	src/lualdap.so
MAKE_FLAGS+=	INST_LIBDIR=${PREFIX:Q}/${LUA_CDIR:Q}

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
