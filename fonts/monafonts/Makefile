# $NetBSD: Makefile,v 1.28 2020/03/20 11:57:39 nia Exp $

DISTNAME=	monafont-2.90
PKGNAME=	${DISTNAME:S/font/fonts/}
PKGREVISION=	9
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://monafont.sourceforge.net/
COMMENT=	Japanese fonts for "Mona" seen at 2ch.net

BUILD_TARGET=	bdf
USE_TOOLS+=	bdftopcf gzip mkdirhier mkfontdir perl sed

MAKE_FLAGS+=	X11FONTDIR=${DESTDIR}${PREFIX}/${FONTS_SUBDIR:Q}
MAKE_FLAGS+=	SED_CMD=${SED:Q}
MAKE_FLAGS+=	PERL_CMD=${PERL5:Q}
MAKE_FLAGS+=	GZIP_CMD=${GZIP_CMD:Q}

FONTS_SUBDIR=	share/fonts/X11/local
FONTS_DIRS.x11=	${FONTS_SUBDIR}

pre-build:
	${MKDIR} ${WRKSRC}/dist

.include "../../mk/bsd.pkg.mk"
