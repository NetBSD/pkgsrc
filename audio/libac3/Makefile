# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:49:47 rh Exp $
#

DISTNAME=	ac3dec-0.6.1
PKGNAME=	${DISTNAME:S/ac3dec/libac3/}
CATEGORIES=	audio
MASTER_SITES=	http://gusnet.cx/aaron/codecs/tarballs/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://ess.engr.uvic.ca/~aholtzma/ac3/

GNU_CONFIGURE=  yes

do-build:
	cd ${WRKSRC}/libac3 && ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libac3/ac3.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libac3/libac3.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
