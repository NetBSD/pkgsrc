# $NetBSD: Makefile,v 1.9 2005/12/02 13:57:49 rillig Exp $
#

DISTNAME=	cuecat-0.2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://opensource.lineo.com/drivers/ \
		http://www.flyingbuttmonkeys.com/mirrors/oss.lineo.com/drivers/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://opensource.lineo.com/cuecat/cuecat_driver/
COMMENT=	Read and parse barcodes from your CueCat barcode reader

RESTRICTED=	Hardware manufacturer claims intellectual property infringement.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/read_cuecat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cuecat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cuecat

.include "../../mk/bsd.pkg.mk"
