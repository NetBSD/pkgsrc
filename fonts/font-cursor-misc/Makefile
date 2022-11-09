# $NetBSD: Makefile,v 1.8 2022/11/09 13:14:12 joerg Exp $
#

DISTNAME=		font-cursor-misc-1.0.3
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Standard X11 cursors in PCF format

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

FONTS_DIRS.x11=		share/fonts/X11/misc

.include "../../mk/bsd.pkg.mk"
