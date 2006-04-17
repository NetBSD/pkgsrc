# $NetBSD: Makefile,v 1.22 2006/04/17 13:46:34 wiz Exp $

DISTNAME=	pngcrush-1.6.2-nolib
PKGNAME=	pngcrush-1.6.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush pngcrush.c \
		-Wall -Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lm -lz -lpng

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
