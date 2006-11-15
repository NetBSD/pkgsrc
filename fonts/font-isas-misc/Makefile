# $NetBSD: Makefile,v 1.1.1.1 2006/11/15 14:56:08 joerg Exp $
#

DISTNAME=		font-isas-misc-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		72dpi PCF versions of the Chinese Song Ti fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config bdftopcf ucs2any

FONTS_DIRS.x11=		lib/X11/fonts/misc

INSTALLATION_DIRS=	share/doc/font-isac-misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-isac-misc

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
