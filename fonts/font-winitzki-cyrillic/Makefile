# $NetBSD: Makefile,v 1.2 2012/06/12 02:10:26 mef Exp $
#

DISTNAME=	font-winitzki-cyrillic-1.0.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Winitzki Cyrillic PCF fonts
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	bdftopcf gzip

FONTS_DIRS.x11=	share/fonts/X11/cyrillic

.include "../../mk/bsd.pkg.mk"
