# $NetBSD: Makefile,v 1.8 2015/06/10 15:44:15 khorben Exp $

DISTNAME=	lgi-${VERSION}
PKGNAME=	${LUA_PKGPREFIX}-gi-${VERSION}
VERSION=	0.9.0
CATEGORIES=	devel
MASTER_SITES=	-https://codeload.github.com/pavouk/lgi/tar.gz/${VERSION}

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
