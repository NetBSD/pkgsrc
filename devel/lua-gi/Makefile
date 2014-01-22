# $NetBSD: Makefile,v 1.4 2014/01/22 16:16:21 jperkin Exp $
#

DISTNAME=	lgi-${VERSION}
PKGNAME=	${LUA_PKGPREFIX}-gi-${VERSION}
VERSION=	0.7.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	-https://codeload.github.com/pavouk/lgi/tar.gz/${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pavouk/lgi
COMMENT=	Gobject-introspection based dynamic Lua binding
LICENSE=	mit

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config gmake
FETCH_USING=	curl
WRKSRC=		${WRKDIR}/pavouk-lgi-1bbf1bc

SUBST_CLASSES+=	v
SUBST_STAGE.v=	pre-build
SUBST_FILES.v=	lgi/Makefile
SUBST_VARS.v=	_LUA_DOT_VERSION

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
