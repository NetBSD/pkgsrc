# $NetBSD: Makefile,v 1.4 2023/02/28 06:54:22 wiz Exp $

DISTNAME=	font-arabic-misc-1.0.4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Arabic PCF fonts
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bdftopcf gzip

FONTS_DIRS.x11=	share/fonts/X11/misc

.include "../../mk/bsd.pkg.mk"
