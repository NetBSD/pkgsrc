# $NetBSD: Makefile,v 1.21 2016/10/03 08:15:50 wiz Exp $

DISTNAME=	libidea-0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.media-crypt.com/pages/fidea.html
COMMENT=	IDEA block cipher library
#LICENSE=	ssleay-license

WRKSRC=		${WRKDIR}/idea
CRYPTO=		YES

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libidea.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/idea.h ${DESTDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/ideatest ${WRKSRC}/idea_spd \
	    ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
