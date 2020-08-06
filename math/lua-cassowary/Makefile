# $NetBSD: Makefile,v 1.1 2020/08/06 23:36:51 joerg Exp $

DISTNAME=	cassowary-2.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	math lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=sile-typesetter/}
GITHUB_PROJECT=	cassowary.lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sile-typesetter/cassowary.lua/
COMMENT=	Constraint solver for Lua
LICENSE=	apache-2.0

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/cassowary.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
