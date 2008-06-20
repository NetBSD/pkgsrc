# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:33 joerg Exp $
#

DISTNAME=		bitstir-0.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.wiredyne.com/software/downloads/

MAINTAINER=		pdh@wiredyne.com
HOMEPAGE=		http://www.wiredyne.com/software/bitstir.html
COMMENT=		Entropy restoration daemon

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bitstir bits-avail ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} bitstir.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bitstir.1

.include "../../mk/bsd.pkg.mk"
