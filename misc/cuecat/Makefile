# $NetBSD: Makefile,v 1.1.1.1 2001/02/13 13:55:42 wiz Exp $
#

DISTNAME=	cuecat-0.2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://opensource.lineo.com/drivers/ \
		http://www.flyingbuttmonkeys.com/mirrors/oss.lineo.com/drivers/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://opensource.lineo.com/cuecat/cuecat_driver/

NO_SOURCE_ON_FTP=	Hardware manufacturer claims intellectual property infringement.
NO_SOURCE_ON_CDROM=	${NO_SOURCE_ON_FTP}
NO_BIN_ON_FTP=		${NO_SOURCE_ON_FTP}
NO_BIN_ON_FTP=		${NO_SOURCE_ON_FTP}

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/read_cuecat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cuecat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cuecat

.include "../../mk/bsd.pkg.mk"
