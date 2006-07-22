# $NetBSD: Makefile,v 1.11 2006/07/22 19:49:11 abs Exp $
#

DISTNAME=	ttf-bitstream-vera-1.10
PKGNAME=	vera-ttf-1.10
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ttf-bitstream-vera/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/fonts/
COMMENT=	Bitstream Vera TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	cd ${WRKSRC} && ${PAX} -rw -pm *.ttf ${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vera-ttf
	${INSTALL_DATA} ${WRKSRC}/local.conf ${PREFIX}/share/examples/vera-ttf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vera-ttf
	cd ${WRKSRC} && ${INSTALL_DATA} *.TXT ${PREFIX}/share/doc/vera-ttf

.include "../../mk/bsd.pkg.mk"
