# $NetBSD: Makefile,v 1.7 2008/03/04 11:02:25 rillig Exp $
#

DISTNAME=		xfrac310
PKGNAME=		xfractint-3.10
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
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

# xfractint sources assume <malloc.h> exists.
# Create a fake one for platforms that don't have it.
#
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then			\
		${ECHO} "#include <stdlib.h>"				\
			> ${BUILDLINK_DIR}/include/malloc.h;		\
	fi

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
