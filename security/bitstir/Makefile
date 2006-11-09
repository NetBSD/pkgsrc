# $NetBSD: Makefile,v 1.6 2006/11/09 11:08:01 rillig Exp $
#

DISTNAME=		bitstir-0.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.wiredyne.com/software/downloads/

MAINTAINER=		pdh@wiredyne.com
HOMEPAGE=		http://www.wiredyne.com/software/bitstir.html
COMMENT=		Entropy restoration daemon

ONLY_FOR_PLATFORM=	NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bitstir bits-avail ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} bitstir.8 ${PREFIX}/${PKGMANDIR}/man1/bitstir.1

.include "../../mk/bsd.pkg.mk"
