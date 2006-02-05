# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:23 joerg Exp $

DISTNAME=		svb
PKGNAME=		svb-1.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://src.doc.ic.ac.uk/public/computing/graphics/systems/X11/R5contrib/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Spy Vs. Bob, the timeless classic

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${INSTALL_GAME_DATA} /dev/null /var/games/svb.scorefile
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${PREFIX}/bin/svb
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/svb
	${INSTALL_MAN} ${WRKSRC}/svb.man ${PREFIX}/man/man6/svb.6

.include "../../mk/bsd.pkg.mk"
