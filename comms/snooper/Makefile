# $NetBSD: Makefile,v 1.17 2005/01/24 01:58:05 tv Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper-19991202
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/ \
		ftp://lkbreth.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper/build
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
