# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:33 jlam Exp $

DISTNAME=		clanbomber-1.01
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/
COMMENT=		Bomberman clone using the ClanLib graphics system

DEPENDS+=		ClanLib>=0.4:../../graphics/clanlib

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include

# needs a valid X display to compile its datafiles
.ifndef DISPLAY
IS_INTERACTIVE=		yes
.endif

pre-configure:
	${ECHO} "#define BOMBERDATDIR \"${X11BASE}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	${ECHO} "#define BOMBERMAPS \"${X11BASE}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

pre-build:
	@if [ "${DISPLAY}" = "" ]; then					    \
		${ECHO} Please set the DISPLAY variable to a valid display; \
		${ECHO} before compiling ${PKGNAME}.;			    \
		exit 1;							    \
	fi;

.include "../../mk/bsd.pkg.mk"
