# $NetBSD: Makefile,v 1.14 2001/10/23 13:14:54 jlam Exp $

DISTNAME=		Pacman-0.3-CVS-00-11-17
PKGNAME=		Pacman-0.3
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/snapshots/Games/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/
COMMENT=		Pacman, a small demonstration game for ClanLib

DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

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

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/clanlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
