# $NetBSD: Makefile,v 1.1.1.1 2010/09/10 05:46:31 obache Exp $
#

DISTNAME=	font-arabic-misc-1.0.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Arabic PCF fonts
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	bdftopcf gzip

FONTS_DIRS.x11=	share/fonts/X11/misc

.include "../../mk/bsd.pkg.mk"
