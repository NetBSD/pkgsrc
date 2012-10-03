# $NetBSD: Makefile,v 1.3 2012/10/03 18:28:21 asau Exp $
#

DISTNAME=	font-misc-meltho-1.0.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Meltho OTF fonts

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.ttf=	share/fonts/X11/OTF

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
