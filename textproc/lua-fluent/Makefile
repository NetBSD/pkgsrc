# $NetBSD: Makefile,v 1.2 2023/04/06 12:14:32 wiz Exp $

DISTNAME=	fluent-0.2.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=alerque/}
GITHUB_PROJECT=	fluent-lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alerque/fluent-lua
COMMENT=	Lua implementation of Project Fluent
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-epnf-[0-9]*:../../devel/lua-epnf
DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-cldr-[0-9]*:../../textproc/lua-cldr

INSTALLATION_DIRS+=	${LUA_LDIR}/fluent

LUA_USE_BUSTED=	yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/fluent/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/fluent

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
