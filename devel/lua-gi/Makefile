# $NetBSD: Makefile,v 1.10 2020/02/15 05:43:48 mef Exp $

DISTNAME=	lgi-${VERSION}
PKGNAME=	${LUA_PKGPREFIX}-gi-${VERSION}
VERSION=	0.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pavouk/}
GITHUB_PROJECT=	lgi

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pavouk/lgi
COMMENT=	Gobject-introspection based dynamic Lua binding
LICENSE=	mit

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	LUA_VERSION=${_LUA_DOT_VERSION}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
