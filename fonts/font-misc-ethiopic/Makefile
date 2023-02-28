# $NetBSD: Makefile,v 1.6 2023/02/28 07:12:02 wiz Exp $

DISTNAME=	font-misc-ethiopic-1.0.5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Ethiopic OTF fonts
LICENSE=	mit

GNU_CONFIGURE=	yes

FONTS_DIRS.ttf=		share/fonts/X11/OTF
FONTS_DIRS.ttf+=	share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
