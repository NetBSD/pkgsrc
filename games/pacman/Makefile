# $NetBSD: Makefile,v 1.9 2001/02/05 09:00:56 tron Exp $

DISTNAME=		Pacman-0.3-CVS-00-11-17
PKGNAME=		Pacman-0.3
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/snapshots/Games/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

DEPENDS+=		ClanLib>=0.2.2:../../graphics/clanlib
DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include
MAKE_ENV+=		LDFLAGS="${LDFLAGS}" CPPFLAGS="${CFLAGS}"

# needs a valid X display to compile its datafiles
.ifndef DISPLAY
IS_INTERACTIVE=		yes
.endif

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf
	${SED} -e 's@/usr/share@${PREFIX}/share@' < ${WRKSRC}/Sources/config.h.in > ${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/Sources/config.h.in

pre-build:
	@if [ "${DISPLAY}" = "" ]; then \
		${ECHO} Please set the DISPLAY variable to a valid display; \
		${ECHO} before compiling ${PKGNAME}.;			    \
		exit 1;							    \
	fi;

.include "../../mk/bsd.pkg.mk"
