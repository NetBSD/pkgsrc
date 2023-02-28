# $NetBSD: Makefile,v 1.9 2023/02/28 07:05:00 wiz Exp $

DISTNAME=		font-cursor-misc-1.0.4
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Standard X11 cursors in PCF format

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

FONTS_DIRS.x11=		share/fonts/X11/misc

.include "../../mk/bsd.pkg.mk"
