# $NetBSD: Makefile,v 1.1.1.1 2001/04/22 08:19:54 tron Exp $

DISTNAME=	nbc-vbi-0.32
CATEGORIES=	audio
MASTER_SITES=	http://kaot.1a.org/download/
EXTRACT_SUFX=	-Source.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://infoworld.wakka.de/linux/nbc-vbi.html
COMMENT=	Client for r@dio.mp3 broadcast service

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/nbc-vbi-src-0.32

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nbc-vbi ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nbc-vbi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nbc-vbi

.include "../../mk/bsd.pkg.mk"
