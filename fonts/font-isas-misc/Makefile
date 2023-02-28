# $NetBSD: Makefile,v 1.9 2023/02/28 07:08:42 wiz Exp $

DISTNAME=		font-isas-misc-1.0.4
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

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
