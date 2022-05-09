# $NetBSD: Makefile,v 1.2 2022/05/09 00:41:57 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${LUA_PKGPREFIX}-${GITHUB_PROJECT:S/lua-//}-1.1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=JorjBauer/}
GITHUB_PROJECT=	lua-cyrussasl
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JorjBauer/lua-cyrussasl/
COMMENT=	Cyrus SASL library for Lua 5.1+
LICENSE=	modified-bsd

USE_LANGUAGES=	c

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	CPATH="${DESTDIR}${PREFIX}/${LUA_CDIR}"
MAKE_FLAGS+=	LDFLAGS="-shared -lsasl2 -L${PREFIX}/lib -Wl,-rpath,${PREFIX}/lib -L${PREFIX}/${LUA_LDIR}"

.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
