# $NetBSD: Makefile,v 1.2 2013/10/16 23:28:49 roy Exp $
#

DISTNAME=	tweak-3.01
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/tweak/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/tweak/
COMMENT=	Efficient hex editor
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
