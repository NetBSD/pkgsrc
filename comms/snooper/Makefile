# $NetBSD: Makefile,v 1.9 2001/08/19 18:48:26 jlam Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper-19991202
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org
COMMENT=	serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper/build
GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	yes

pre-build:
	cd ${WRKSRC} ; ${MAKE_PROGRAM} depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
