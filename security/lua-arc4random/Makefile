# $NetBSD: Makefile,v 1.6 2023/10/24 22:10:51 wiz Exp $

DISTNAME=	lua-arc4random-1.4.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
PKGREVISION=	1
CATEGORIES=	security lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikejsavage/}
GITHUB_PROJECT=	lua-arc4random
GITHUB_TAG=	v1.4-1

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mikejsavage/lua-arc4random
COMMENT=	Lua wrapper for arc4random(3)
LICENSE=	isc

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/arc4random.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.  include "../../security/openssl/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
