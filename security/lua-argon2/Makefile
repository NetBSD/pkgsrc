# $NetBSD: Makefile,v 1.1 2020/07/02 14:02:36 nia Exp $

DISTNAME=	lua-argon2-3.0.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	security lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=thibaultcha/}
GITHUB_PROJECT=	lua-argon2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://thibaultcha.github.io/lua-argon2/
COMMENT=	Lua C binding for the Argon2 password hashing algorithm
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/argon2.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
