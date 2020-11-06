# $NetBSD: Makefile,v 1.21 2020/11/06 18:04:27 maya Exp $
#

# The "vera-ttf" package must always contain unmodified TTF files according
# to the terms of the license.
# If you need to alter the TTF files you must import the package under a
# different name that does not include the words "Vera" or Bitstream".

DISTNAME=	ttf-bitstream-vera-1.10
PKGNAME=	vera-ttf-1.10
PKGREVISION=	6
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ttf-bitstream-vera/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/fonts/
COMMENT=	Bitstream Vera TrueType fonts
LICENSE=	vera-ttf-license

INSTALLATION_DIRS+=	share/doc/vera-ttf share/examples/vera-ttf

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/local.conf ${DESTDIR}${PREFIX}/share/examples/vera-ttf
	cd ${WRKSRC} && ${INSTALL_DATA} *.TXT ${DESTDIR}${PREFIX}/share/doc/vera-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
