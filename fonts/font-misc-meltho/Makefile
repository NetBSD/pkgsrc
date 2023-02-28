# $NetBSD: Makefile,v 1.4 2023/02/28 07:12:57 wiz Exp $

DISTNAME=	font-misc-meltho-1.0.4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.freedesktop.org/pub/individual/font/
COMMENT=	Miscellaneous Meltho OTF fonts

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.ttf=	share/fonts/X11/OTF

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
