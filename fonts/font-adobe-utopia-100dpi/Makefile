# $NetBSD: Makefile,v 1.5 2010/09/09 02:21:01 joerg Exp $
#

DISTNAME=		font-adobe-utopia-100dpi-1.0.2
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		100dpi Adobe Utopia PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/100dpi

INSTALLATION_DIRS=	share/doc/font-adobe-utopia-100dpi

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-adobe-utopia-100dpi

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
