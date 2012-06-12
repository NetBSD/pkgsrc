# $NetBSD: Makefile,v 1.3 2012/06/12 02:10:26 mef Exp $
#

DISTNAME=		font-sun-misc-1.0.3
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Sun Open Look PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		bdftopcf gzip

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.x11=		share/fonts/X11/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
