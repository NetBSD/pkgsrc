# $NetBSD: Makefile,v 1.12 2003/07/21 16:35:16 martti Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper-19991202
WRKSRC=		${WRKDIR}/snooper/build
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
