# $NetBSD: Makefile,v 1.2 2011/07/12 13:45:51 wiz Exp $
#

DISTNAME=	font-schumacher-misc-1.1.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Schumacher Miscellaneous "Crean" PCF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bdftopcf gzip ucs2any

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.x11=	share/fonts/X11/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../fonts/font-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
