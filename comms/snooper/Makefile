# $NetBSD: Makefile,v 1.6 2001/01/29 11:34:22 wiz Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper-19991202
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/snooper/build
GNU_CONFIGURE=	yes

pre-build:
	cd ${WRKSRC} ; ${MAKE} depend

post-install:
	${MKDIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
