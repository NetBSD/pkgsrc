# $NetBSD: Makefile,v 1.8 2020/01/26 17:31:12 rillig Exp $
#

DISTNAME=	tamsyn-font-1.11
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.fial.com/~scott/tamsyn-font/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fial.com/~scott/tamsyn-font/
COMMENT=	Monospaced programming font
# even less restrictions than that
LICENSE=	isc

FONTDIR=		${PREFIX}/share/fonts/X11/tamsyn-font
FONTS_DIRS.x11+=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/tamsyn-font

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/T* ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/tamsyn-font
	${INSTALL_DATA} ${WRKSRC}/READ* ${DESTDIR}${PREFIX}/share/doc/tamsyn-font

.include "../../mk/bsd.pkg.mk"
