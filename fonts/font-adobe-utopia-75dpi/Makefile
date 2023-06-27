# $NetBSD: Makefile,v 1.12 2023/06/27 10:43:33 riastradh Exp $

DISTNAME=		font-adobe-utopia-75dpi-1.0.5
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		75dpi Adobe Utopia PCF fonts

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/75dpi

INSTALLATION_DIRS=	share/doc/font-adobe-utopia-75dpi

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-adobe-utopia-75dpi

.include "../../fonts/font-util/pkgconfig.mk"

.include "../../mk/bsd.pkg.mk"
