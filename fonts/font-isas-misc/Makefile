# $NetBSD: Makefile,v 1.8 2022/11/09 13:14:12 joerg Exp $
#

DISTNAME=		font-isas-misc-1.0.3
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		72dpi PCF versions of the Chinese Song Ti fonts

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config bdftopcf ucs2any gzip

FONTS_DIRS.x11=		share/fonts/X11/misc

INSTALLATION_DIRS=	share/doc/font-isac-misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-isac-misc

.include "../../fonts/font-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
