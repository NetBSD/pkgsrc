# $NetBSD: Makefile,v 1.2 2013/07/25 13:05:18 degroote Exp $
#

DISTNAME=	lgi-${VERSION}
PKGNAME=	lua-gi-${VERSION}
VERSION=	0.7.1
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

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
