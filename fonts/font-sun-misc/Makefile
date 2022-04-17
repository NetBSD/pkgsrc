# $NetBSD: Makefile,v 1.6 2022/04/17 00:26:14 gutteridge Exp $
#

DISTNAME=		font-sun-misc-1.0.3
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Sun Open Look PCF fonts
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.x11=		share/fonts/X11/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
