# $NetBSD: Makefile,v 1.4 2003/07/21 16:30:41 martti Exp $
#

DISTNAME=	ac3dec-0.6.1
PKGNAME=	${DISTNAME:S/ac3dec/libac3/}
CATEGORIES=	audio
MASTER_SITES=	http://gusnet.cx/aaron/codecs/tarballs/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://ess.engr.uvic.ca/~aholtzma/ac3/
COMMENT=	AC3 audio (as used on DVDs) decoding library

GNU_CONFIGURE=  yes

do-build:
	cd ${WRKSRC}/libac3 && ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libac3/ac3.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libac3/libac3.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
