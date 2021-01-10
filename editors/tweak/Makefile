# $NetBSD: Makefile,v 1.6 2021/01/10 11:20:17 fcambus Exp $
#

DISTNAME=	tweak-3.02
CATEGORIES=	editors
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/
COMMENT=	Efficient hex editor
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
