# $NetBSD: Makefile,v 1.20 2005/11/03 20:01:20 rillig Exp $

DISTNAME=	snooper-19991202
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/ \
		ftp://lkbreth.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
