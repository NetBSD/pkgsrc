# $NetBSD: Makefile,v 1.7 2015/09/23 11:34:16 ryoon Exp $
#

DISTNAME=	roboto-fonts-20150923
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.google.com/fonts/specimen/Roboto
COMMENT=	Roboto font family from Google's Android
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

INSTALL_FONTS=	Roboto-Black.ttf \
		Roboto-BlackItalic.ttf \
		Roboto-Bold.ttf \
		Roboto-BoldItalic.ttf \
		Roboto-Italic.ttf \
		Roboto-Light.ttf \
		Roboto-LightItalic.ttf \
		Roboto-Medium.ttf \
		Roboto-MediumItalic.ttf \
		Roboto-Regular.ttf \
		Roboto-Thin.ttf \
		Roboto-ThinItalic.ttf \
		RobotoCondensed-Bold.ttf \
		RobotoCondensed-BoldItalic.ttf \
		RobotoCondensed-Italic.ttf \
		RobotoCondensed-Light.ttf \
		RobotoCondensed-LightItalic.ttf \
		RobotoCondensed-Regular.ttf

do-install:
.for i in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
