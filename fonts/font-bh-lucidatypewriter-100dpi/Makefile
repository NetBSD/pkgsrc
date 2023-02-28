# $NetBSD: Makefile,v 1.9 2023/02/28 06:57:45 wiz Exp $

DISTNAME=		font-bh-lucidatypewriter-100dpi-1.0.4
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		100dpi Bigelow & Holmes Lucida Typewriter PCF fonts

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/100dpi

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
