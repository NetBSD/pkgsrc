# $NetBSD: Makefile,v 1.26 2001/01/13 03:24:26 jlam Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp

DISTNAME=	libpng-1.0.8
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		ftp://ftp.cdrom.com/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libpng.org/pub/png/

USE_LIBTOOL=	yes

MAKEFILE=	scripts/makefile.std
MAKE_ENV+=	REALCC=${CC}

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
