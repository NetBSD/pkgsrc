# $NetBSD: Makefile,v 1.1 2020/07/08 15:10:38 nia Exp $

DISTNAME=	lua-iconv-7
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	converters lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=ittner/}
GITHUB_PROJECT=	lua-iconv
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ittner.com.br/lua-iconv/
COMMENT=	Lua bindings for POSIX iconv
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/iconv.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
