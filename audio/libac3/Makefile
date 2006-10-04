# $NetBSD: Makefile,v 1.8 2006/10/04 20:44:19 wiz Exp $
#

DISTNAME=	ac3dec-0.6.1
PKGNAME=	${DISTNAME:S/ac3dec/libac3/}
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://liba52.sourceforge.net/
# obsolete -- remove in favor of liba52?
COMMENT=	AC3 audio (as used on DVDs) decoding library

GNU_CONFIGURE=  yes

INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC}/libac3 && ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libac3/ac3.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libac3/libac3.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
