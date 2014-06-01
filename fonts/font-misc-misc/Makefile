# $NetBSD: Makefile,v 1.6 2014/06/01 16:35:33 wiz Exp $
#

DISTNAME=		font-misc-misc-1.1.2
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard X11 "fixed" PCF font

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/misc

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
