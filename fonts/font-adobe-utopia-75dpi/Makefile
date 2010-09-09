# $NetBSD: Makefile,v 1.6 2010/09/09 17:59:36 joerg Exp $
#

DISTNAME=		font-adobe-utopia-75dpi-1.0.2
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		75dpi Adobe Utopia PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/75dpi

INSTALLATION_DIRS=	share/doc/font-adobe-utopia-75dpi

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-adobe-utopia-75dpi

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
