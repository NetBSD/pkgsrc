# $NetBSD: Makefile,v 1.19 2000/06/01 11:23:31 rh Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp

DISTNAME=       libpng-1.0.6
PKGNAME=        png-1.0.6
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.cdrom.com/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.cdrom.com/pub/png/

USE_PKGLIBTOOL=	yes

MAKEFILE=       scripts/makefile.std

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
