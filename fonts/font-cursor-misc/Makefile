# $NetBSD: Makefile,v 1.4 2010/09/09 18:26:20 joerg Exp $
#

DISTNAME=		font-cursor-misc-1.0.1
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard X11 cursors in PCF format

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

FONTS_DIRS.x11=		share/fonts/X11/misc

.include "../../mk/bsd.pkg.mk"
