# $NetBSD: Makefile,v 1.11 2017/01/07 21:58:46 zafer Exp $
#

DISTNAME=		xfrac310
PKGNAME=		xfractint-3.10
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		http://www.nahee.com/spanky/pub/fractals/programs/unix/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nahee.com/spanky/www/fractint/xfractint_port.html
COMMENT=		Fractint for X11

WRKSRC=			${WRKDIR}
USE_LIBTOOL=		yes

MAKE_FLAGS+=		BINDIR=${PREFIX}/bin
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=		SRCDIR=${PREFIX}/share/xfractint
BUILD_TARGET=		xfractint
BUILDLINK_TRANSFORM+=	l:ncurses:curses

INSTALLATION_DIRS=	bin $(PKGMANDIR)/man1 share/xfractint

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
