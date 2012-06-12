# $NetBSD: Makefile,v 1.2 2012/06/12 02:10:25 mef Exp $
#

DISTNAME=	font-misc-ethiopic-1.0.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Ethiopic OTF fonts
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

FONTS_DIRS.ttf=	share/fonts/X11/OTF
FONTS_DIRS.ttf+=share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
