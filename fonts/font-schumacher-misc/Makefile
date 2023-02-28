# $NetBSD: Makefile,v 1.4 2023/02/28 07:16:34 wiz Exp $

DISTNAME=	font-schumacher-misc-1.1.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Schumacher Miscellaneous "Crean" PCF fonts

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bdftopcf gzip ucs2any

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.x11=	share/fonts/X11/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../fonts/font-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
