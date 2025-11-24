# $NetBSD: Makefile,v 1.10 2025/11/24 08:21:47 wiz Exp $

DISTNAME=		bitstir-0.2
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		https://www.wiredyne.com/software/downloads/

MAINTAINER=		pdh@wiredyne.com
HOMEPAGE=		https://www.wiredyne.com/software/bitstir.html
COMMENT=		Entropy restoration daemon

ONLY_FOR_PLATFORM=	NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bitstir bits-avail ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} bitstir.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bitstir.1

.include "../../mk/bsd.pkg.mk"
