# $NetBSD: Makefile,v 1.5 2020/01/28 13:23:32 fcambus Exp $
#

DISTNAME=	tweak-3.02
CATEGORIES=	editors
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/
COMMENT=	Efficient hex editor
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
