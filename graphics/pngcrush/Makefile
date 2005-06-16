# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=	pngcrush-1.5.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

NO_CONFIGURE=		YES
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush pngcrush.c \
		-Wall -Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lm -lz -lpng

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/pngcrush
	${INSTALL_MAN} ${WRKSRC}/README.txt ${PREFIX}/share/pngcrush

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
