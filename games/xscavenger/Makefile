# $NetBSD: Makefile,v 1.1.1.1 2000/01/08 18:26:00 wiz Exp $
#

DISTNAME=	xscavenger-140
PKGNAME=	xscavenger-1.4.0
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.xdr.com/dash/scavenger.html

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/scavenger.6 ${PREFIX}/man/man6/
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scavenger
	@ ${INSTALL_MAN} ${WRKSRC}/../DOC ${PREFIX}/share/doc/scavenger

.include "../../mk/bsd.pkg.mk"
