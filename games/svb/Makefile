# $NetBSD: Makefile,v 1.8 2004/01/20 12:15:41 agc Exp $

DISTNAME=		svb
PKGNAME=		svb-1.0
CATEGORIES=		games x11
MASTER_SITES=		http://src.doc.ic.ac.uk/public/computing/graphics/systems/X11/R5contrib/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Spy Vs. Bob, the timeless classic

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${TOUCH} /var/games/svb.scorefile
	${CHOWN} games:games /var/games/svb.scorefile
	${CHMOD} 664 /var/games/svb.scorefile
	${CHOWN} bin:games ${PREFIX}/bin/svb
	${CHMOD} 2755 ${PREFIX}/bin/svb
	${INSTALL_MAN} ${WRKSRC}/svb.man ${PREFIX}/man/man6/svb.6

.include "../../mk/bsd.pkg.mk"
