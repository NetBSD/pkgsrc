# $NetBSD: Makefile,v 1.32 2001/05/21 21:39:13 wiz Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.0.11
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		ftp://ftp.cdrom.com/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

USE_LIBTOOL=	yes

MAKEFILE=	scripts/makefile.std
MAKE_ENV+=	REALCC="${CC}"

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
