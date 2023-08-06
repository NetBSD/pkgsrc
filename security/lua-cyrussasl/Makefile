# $NetBSD: Makefile,v 1.3 2023/08/06 10:14:50 nia Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${LUA_PKGPREFIX}-${GITHUB_PROJECT:S/lua-//}-1.1.0
PKGREVISION=	1
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

CFLAGS+=	-fPIC
MAKE_FLAGS+=	CPATH="${DESTDIR}${PREFIX}/${LUA_CDIR}"
MAKE_FLAGS+=	LDFLAGS="-shared -lsasl2 -L${PREFIX}/lib -Wl,-rpath,${PREFIX}/lib -L${PREFIX}/${LUA_LDIR} ${LDFLAGS}"

.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
