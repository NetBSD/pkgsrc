# $NetBSD: Makefile,v 1.5 2014/07/17 14:31:46 ryoon Exp $
#

DISTNAME=	RobotoTTF
PKGNAME=	roboto-fonts-20140716
CATEGORIES=	fonts
MASTER_SITES=	http://material-design.storage.googleapis.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.google.com/design/spec/style/typography.html
COMMENT=	Roboto font family from Google's Android 4
LICENSE=	apache-2.0

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none
USE_X11BASE=	yes
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
		RobotoCondensed-LightItalic.ttf

do-install:
.for i in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
