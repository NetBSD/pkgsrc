# $NetBSD: Makefile,v 1.2 2008/01/22 17:09:54 tnn Exp $
#

DISTNAME=		font-sony-misc-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard X11 "sony" PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		lib/X11/fonts/misc

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
