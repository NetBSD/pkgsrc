# $NetBSD: Makefile,v 1.4 2017/09/06 09:03:01 wiz Exp $
#

DISTNAME=	tweak-3.01
PKGREVISION=	2
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
