# $NetBSD: Makefile,v 1.1.1.1 2006/11/15 11:24:09 joerg Exp $
#

DISTNAME=		font-bh-ttf-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF
FONTS_DIRS.x11=		lib/X11/fonts/TTF

INSTALLATION_DIRS=	share/doc/font-bh-ttf

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-ttf

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
