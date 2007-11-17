# $NetBSD: Makefile,v 1.24 2007/11/17 13:40:16 wiz Exp $

DISTNAME=	snooper-19991202
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

post-extract:
	${RM} ${WRKSRC}/build/.depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
