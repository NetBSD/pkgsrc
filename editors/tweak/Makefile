# $NetBSD: Makefile,v 1.8 2022/06/27 15:29:15 fcambus Exp $
#

DISTNAME=	tweak-3.02
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/tweak/
COMMENT=	Efficient hex editor
LICENSE=	mit

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
