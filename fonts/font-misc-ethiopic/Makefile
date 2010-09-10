# $NetBSD: Makefile,v 1.1.1.1 2010/09/10 05:51:30 obache Exp $
#

DISTNAME=	font-misc-ethiopic-1.0.1
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
