# $NetBSD: Makefile,v 1.15 2004/01/12 21:23:05 adam Exp $
#

DISTNAME=	pngcrush-1.5.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

USE_BUILDLINK2=		# defined
NO_CONFIGURE=		YES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush pngcrush.c \
		-Wall -Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lm -lz -lpng

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/pngcrush
	${INSTALL_MAN} ${WRKSRC}/README.txt ${PREFIX}/share/pngcrush

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
