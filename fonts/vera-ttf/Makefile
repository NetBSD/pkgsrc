# $NetBSD: Makefile,v 1.19 2017/07/30 22:47:50 wiz Exp $
#

# The "vera-ttf" package must always contain unmodified TTF files according
# to the terms of the license.
# If you need to alter the TTF files you must import the package under a
# different name that does not include the words "Vera" or Bitstream".

DISTNAME=	ttf-bitstream-vera-1.10
PKGNAME=	vera-ttf-1.10
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ttf-bitstream-vera/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/fonts/
COMMENT=	Bitstream Vera TrueType fonts
LICENSE=	vera-ttf-license

NO_CONFIGURE=	YES
NO_BUILD=	YES

USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			share/doc/vera-ttf share/examples/vera-ttf
FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

do-install:
	cd ${WRKSRC} && pax -rw -pm *.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/local.conf ${DESTDIR}${PREFIX}/share/examples/vera-ttf
	cd ${WRKSRC} && ${INSTALL_DATA} *.TXT ${DESTDIR}${PREFIX}/share/doc/vera-ttf

.include "../../mk/bsd.pkg.mk"
