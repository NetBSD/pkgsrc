# $NetBSD: Makefile,v 1.6 2010/09/09 17:59:37 joerg Exp $
#

DISTNAME=		font-adobe-75dpi-1.0.1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard 75pi Adobe PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/75dpi

INSTALLATION_DIRS=	share/doc/font-adobe-75dpi

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-adobe-75dpi

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
