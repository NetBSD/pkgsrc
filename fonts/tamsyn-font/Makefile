# $NetBSD: Makefile,v 1.2 2011/10/20 11:32:11 wiz Exp $
#

DISTNAME=	tamsyn-font-1.6
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.fial.com/~scott/tamsyn-font/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fial.com/~scott/tamsyn-font/
COMMENT=	Monospaced programming font
# even less restrictions than that
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

FONTDIR=		${PREFIX}/lib/X11/fonts/tamsyn-font
FONTS_DIRS.x11+=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/tamsyn-font

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/T* ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/tamsyn-font
	${INSTALL_DATA} ${WRKSRC}/READ* ${DESTDIR}${PREFIX}/share/doc/tamsyn-font

.include "../../mk/bsd.pkg.mk"
