# $NetBSD: Makefile,v 1.1 1998/09/07 03:23:09 garbled Exp $

DISTNAME=		svb
PKGNAME=		svb-1.0
CATEGORIES=		games x11
MASTER_SITES=		http://src.doc.ic.ac.uk/public/computing/graphics/systems/X11/R5contrib/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		root@garbled.net

USE_IMAKE=		yes
NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=	#empty
EXTRACT_AFTER_ARGS=	|sh
NO_INSTALL_MANPAGES=	yes

post-install:
	${TOUCH} /var/games/svb.scorefile
	chown games:games /var/games/svb.scorefile
	chmod 664 /var/games/svb.scorefile
	chown bin:games ${PREFIX}/bin/svb
	chmod 2755 ${PREFIX}/bin/svb
	${INSTALL_MAN} ${WRKSRC}/svb.man ${PREFIX}/man/man6/svb.6

.include "../../mk/bsd.pkg.mk"
