# $NetBSD: Makefile,v 1.4 2023/02/28 07:04:07 wiz Exp $

DISTNAME=	font-cronyx-cyrillic-1.0.4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Cronyx Cyrillic PCF fonts

GNU_CONFIGURE=	yes
USE_TOOLS+=	bdftopcf gzip

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.x11=	share/fonts/X11/cyrillic

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
