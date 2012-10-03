# $NetBSD: Makefile,v 1.5 2012/10/03 18:28:21 asau Exp $
#

DISTNAME=		font-misc-misc-1.1.2
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard X11 "fixed" PCF font

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		lib/X11/fonts/misc

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
