# $NetBSD: Makefile,v 1.12 2001/10/12 09:22:36 rh Exp $
#

DISTNAME=	pngcrush-1.5.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

NO_CONFIGURE=	YES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush *.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/pngcrush
	${INSTALL_MAN} ${WRKSRC}/README.txt ${PREFIX}/share/pngcrush

.include "../../mk/bsd.pkg.mk"
