# $NetBSD: Makefile,v 1.5 2004/01/20 12:15:42 agc Exp $
#

DISTNAME=	xscavenger-1.4.4
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xdr.com/dash/scavenger.html
COMMENT=	Loderunner clone with sound for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/scavenger.6 ${PREFIX}/man/man6/
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scavenger
	@ ${INSTALL_MAN} ${WRKSRC}/../DOC ${PREFIX}/share/doc/scavenger

.include "../../mk/bsd.pkg.mk"
