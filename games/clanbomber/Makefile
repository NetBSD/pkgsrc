# $NetBSD: Makefile,v 1.13 2001/11/29 01:12:32 hubertf Exp $

DISTNAME=		clanbomber-1.01
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/
COMMENT=		Bomberman clone using the ClanLib graphics system

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

# needs a valid X display to compile its datafiles
.ifndef DISPLAY
IS_INTERACTIVE=		yes
.endif

pre-configure:
	${ECHO} "#define BOMBERDATDIR \"${X11PREFIX}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	${ECHO} "#define BOMBERMAPS \"${X11PREFIX}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

pre-build:
	@if [ "${DISPLAY}" = "" ]; then					    \
		${ECHO} Please set the DISPLAY variable to a valid display; \
		${ECHO} before compiling ${PKGNAME}.;			    \
		exit 1;							    \
	fi;

.include "../../graphics/clanlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
