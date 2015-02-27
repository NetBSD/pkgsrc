# $NetBSD: Makefile,v 1.20 2015/02/27 14:35:01 tnn Exp $
#

DISTNAME=	libidea-0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.media-crypt.com/pages/fidea.html
COMMENT=	IDEA block cipher library
LICENSE=	idea-license

RESTRICTED=	IDEA is a patented algorithm that requires proper licensing
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

WRKSRC=		${WRKDIR}/idea
CRYPTO=		YES

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libidea.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/idea.h ${DESTDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/ideatest ${WRKSRC}/idea_spd \
	    ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
