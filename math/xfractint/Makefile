# $NetBSD: Makefile,v 1.3 2006/06/14 09:07:45 rillig Exp $
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
MAKE_FLAGS+=		SRCDIR=${PREFIX}/share/xfractint
BUILD_TARGET=		xfractint
BUILDLINK_TRANSFORM+=	l:ncurses:curses

INSTALLATION_DIRS=	share/xfractint

.include "../../mk/curses.buildlink3.mk"
.include "../../pkgtools/x11-links/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
