# $NetBSD: Makefile,v 1.2 2003/04/17 14:26:06 salo Exp $
#

DISTNAME=	ttf-bitstream-vera-1.10
PKGREVISION=	1
PKGNAME=	vera-ttf-1.10
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ttf-bitstream-vera/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/fonts/
COMMENT=	Bitstream Vera TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TrueType

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	cd ${WRKSRC} && ${PAX} -rw -pm *.ttf ${PREFIX}/lib/X11/fonts/TrueType/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vera-ttf
	${INSTALL_DATA} ${WRKSRC}/local.conf ${PREFIX}/share/examples/vera-ttf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vera-ttf
	cd ${WRKSRC} && ${INSTALL_DATA} *.TXT ${PREFIX}/share/doc/vera-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
