# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:21 tnn Exp $
#

DISTNAME=		font-cursor-misc-1.0.0
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard X11 cursors in PCF format

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

FONTS_DIRS.x11=		lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
