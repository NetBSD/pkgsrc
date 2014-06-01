# $NetBSD: Makefile,v 1.4 2014/06/01 16:35:37 wiz Exp $
#

DISTNAME=	roboto-fonts-20111115a
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://source.android.com/
COMMENT=	Roboto font family from Google's Android 4
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_X11BASE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${PREFIX}/share/doc/${PKGBASE}

INSTALL_FONTS=	Roboto-Bold.ttf \
		Roboto-BoldCondensed.ttf \
		Roboto-BoldCondensedItalic.ttf \
		Roboto-BoldItalic.ttf \
		Roboto-Condensed.ttf \
		Roboto-CondensedItalic.ttf \
		Roboto-Italic.ttf \
		Roboto-Regular.ttf

do-install:
.for i in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${FONTDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
