# $NetBSD: Makefile,v 1.3 2003/07/17 21:39:44 grant Exp $
#

DISTNAME=	xscavenger-140
PKGNAME=	xscavenger-1.4.0
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xdr.com/dash/scavenger.html
COMMENT=	Loderunner clone with sound for X11

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/scavenger.6 ${PREFIX}/man/man6/
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scavenger
	@ ${INSTALL_MAN} ${WRKSRC}/../DOC ${PREFIX}/share/doc/scavenger

.include "../../mk/bsd.pkg.mk"
