# $NetBSD: Makefile,v 1.3 2012/10/03 18:28:30 asau Exp $
#

DISTNAME=	roboto-fonts-20111115a
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

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
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
