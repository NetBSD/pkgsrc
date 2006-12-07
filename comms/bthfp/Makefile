# $NetBSD: Makefile,v 1.1.1.1 2006/12/07 20:29:10 plunky Exp $

DISTNAME=		bthfp-0.1
CATEGORIES=		comms
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		bthfp-0.1.tar.gz

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth Handsfree Profile

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

BUILD_DEFS+=		PKGMANDIR

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bthfp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bthfp.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
