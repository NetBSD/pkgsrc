# $NetBSD: Makefile,v 1.8 2012/06/11 23:23:29 mef Exp $
#

DISTNAME=		font-adobe-utopia-type1-1.0.4
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Adobe Utopia Type1 fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TOOLS_CMD.true:Q}

FONTS_DIRS.type1=	lib/X11/fonts/Type1
FONTS_DIRS.x11=		lib/X11/fonts/Type1

INSTALLATION_DIRS=	share/doc/font-adobe-utopia-type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-adobe-utopia-type1

.include "../../mk/bsd.pkg.mk"
