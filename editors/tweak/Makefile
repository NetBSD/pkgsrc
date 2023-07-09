# $NetBSD: Makefile,v 1.9 2023/07/09 15:27:00 nia Exp $
#

DISTNAME=	tweak-3.02
PKGREVISION=	2
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
