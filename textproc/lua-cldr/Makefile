# $NetBSD: Makefile,v 1.1 2023/04/06 12:05:32 joerg Exp $

DISTNAME=	cldr-0.3.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=alerque/}
GITHUB_PROJECT=	cldr-lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alerque/cldr-lua
COMMENT=	Lua Unicode CLDR interface
LICENSE=	mit AND unicode

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}/cldr/data

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/cldr/init.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cldr
	${INSTALL_DATA} ${WRKSRC}/cldr/data/locales.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cldr/data

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
