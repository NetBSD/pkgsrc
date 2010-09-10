# $NetBSD: Makefile,v 1.1.1.1 2010/09/10 05:52:47 obache Exp $
#

DISTNAME=	font-misc-meltho-1.0.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Meltho OTF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.ttf=	share/fonts/X11/OTF

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
