# $NetBSD: Makefile,v 1.18 2002/07/02 11:34:03 agc Exp $

DISTNAME=		Pacman-0.3-CVS-00-11-17
PKGNAME=		Pacman-0.3
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/snapshots/Games/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/
COMMENT=		Pacman, a small demonstration game for ClanLib

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

# needs a valid X display to compile its datafiles
.ifndef DISPLAY
INTERACTIVE_STAGE=	build
.endif

pre-configure:
	${CP} ${FILESDIR}/configure ${WRKSRC}
	${SED} -e 's@/usr/share@${PREFIX}/share@' < \
		${WRKSRC}/Sources/config.h.in > ${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/Sources/config.h.in

pre-build:
	@if [ "${DISPLAY}" = "" ]; then \
		${ECHO} Please set the DISPLAY variable to a valid display; \
		${ECHO} before compiling ${PKGNAME}.;			    \
		exit 1;							    \
	fi;

.include "../../graphics/clanlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
