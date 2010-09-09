# $NetBSD: Makefile,v 1.6 2010/09/09 18:13:19 joerg Exp $
#

DISTNAME=		font-bh-ttf-1.0.1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TOOLS_CMD.true:Q}

FONTS_DIRS.ttf=		share/fonts/X11/TTF
FONTS_DIRS.x11=		share/fonts/X11/TTF

INSTALLATION_DIRS=	share/doc/font-bh-ttf

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-ttf

.include "../../mk/bsd.pkg.mk"
