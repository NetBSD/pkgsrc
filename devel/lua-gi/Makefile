# $NetBSD: Makefile,v 1.1 2013/07/22 19:38:07 degroote Exp $
#

PKGNAME=	lua-gi-${VERSION}
VERSION=	0.7.1
DISTNAME=	${VERSION}
CATEGORIES=		devel
MASTER_SITES=	http://github.com/pavouk/lgi/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pavouk/lgi
COMMENT=	Gobject-introspection based dynamic Lua binding
LICENSE=	mit

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config gmake

WRKSRC=		${WRKDIR}/lgi-${VERSION}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
