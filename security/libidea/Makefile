# $NetBSD: Makefile,v 1.1.1.1 2000/11/29 11:30:55 rh Exp $
#

DISTNAME=	libidea-0.8.2b
WRKSRC=		${WRKDIR}/idea
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.psy.uq.oz.au/pub/Crypto/libeay/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/ \
		ftp://ftp.ntnu.no/pub/unix/security/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/libeay/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.media-crypt.com/pages/fidea.html

CRYPTO=		YES

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} libidea.a ${PREFIX}/lib &&			\
	${INSTALL_DATA} idea.h ${PREFIX}/include &&			\
	${INSTALL_PROGRAM} ideatest idea_spd ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
