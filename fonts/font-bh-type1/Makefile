# $NetBSD: Makefile,v 1.2 2006/11/15 14:00:21 joerg Exp $
#

DISTNAME=		font-bh-type1-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

FONTS_DIRS.type1=	lib/X11/fonts/Type1
FONTS_DIRS.x11=		lib/X11/fonts/Type1

INSTALLATION_DIRS=	share/doc/font-bh-type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-type1

.include "../../mk/bsd.pkg.mk"
