# $NetBSD: Makefile,v 1.3 2012/10/03 18:28:22 asau Exp $
#

DISTNAME=	font-winitzki-cyrillic-1.0.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Winitzki Cyrillic PCF fonts
LICENSE=	public-domain

GNU_CONFIGURE=	yes
USE_TOOLS+=	bdftopcf gzip

FONTS_DIRS.x11=	share/fonts/X11/cyrillic

.include "../../mk/bsd.pkg.mk"
