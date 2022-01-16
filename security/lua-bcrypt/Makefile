# $NetBSD: Makefile,v 1.4 2022/01/16 13:41:13 nia Exp $

DISTNAME=	lua-bcrypt-2.2-1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1:S/-1/.1/g}
CATEGORIES=	security lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikejsavage/}
GITHUB_PROJECT=	lua-bcrypt
GITHUB_TAG=	v2.2-1

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mikejsavage/lua-bcrypt
COMMENT=	Lua wrapper for the bcrypt password hashing function
LICENSE=	isc

USE_TOOLS+=	gmake

BUILD_DIRS+=	src

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/bcrypt.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

do-test:
	cd ${WRKSRC}/src && \
	    ${LUA_INTERPRETER} ${WRKSRC}/test-digest.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.  include "../../security/openssl/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
