# $NetBSD: Makefile,v 1.3 2001/01/04 01:08:55 wiz Exp $

DISTNAME=		clanbomber-1.01
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/

DEPENDS+=		ClanLib>=0.4:../../graphics/clanlib

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
	echo "#define BOMBERDATDIR \"${X11BASE}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	echo "#define BOMBERMAPS \"${X11BASE}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

pre-build:
	@if [ "${DISPLAY}" = "" ]; then					    \
		${ECHO} Please set the DISPLAY variable to a valid display; \
		${ECHO} before compiling ${PKGNAME}.;			    \
		exit 1;							    \
	fi;

.include "../../mk/bsd.pkg.mk"
