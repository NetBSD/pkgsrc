# $NetBSD: Makefile,v 1.8 2001/02/25 04:17:38 hubertf Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper-19991202
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org
COMMENT=	serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper/build
GNU_CONFIGURE=	yes

pre-build:
	cd ${WRKSRC} ; ${MAKE} depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
