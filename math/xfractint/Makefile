# $NetBSD: Makefile,v 1.4.2.1 2007/05/15 22:19:50 salo Exp $
#

DISTNAME=		xfrac310
PKGNAME=		xfractint-3.10
PKGREVISION=		1
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

MAKE_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
