# $NetBSD: Makefile,v 1.3 2008/06/21 20:47:28 joerg Exp $

DISTNAME=		bthfp-0.1
CATEGORIES=		comms
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		bthfp-0.1.tar.gz

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth Handsfree Profile

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bthfp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bthfp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
