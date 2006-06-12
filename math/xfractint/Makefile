# $NetBSD: Makefile,v 1.1.1.1 2006/06/12 14:13:55 rillig Exp $
#

DISTNAME=		xfrac310
PKGNAME=		xfractint-3.10
CATEGORIES=		math
MASTER_SITES=		http://spanky.triumf.ca/pub/fractals/programs/unix/
EXTRACT_SUFX=		.zip

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://spanky.triumf.ca/pub/fractals/programs/unix/
COMMENT=		Fractint for X11

WRKSRC=			${WRKDIR}
USE_LIBTOOL=		yes

MAKE_FLAGS+=		BINDIR=${PREFIX}/bin
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
BUILD_TARGET=		xfractint
BUILDLINK_TRANSFORM+=	l:ncurses:curses

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
