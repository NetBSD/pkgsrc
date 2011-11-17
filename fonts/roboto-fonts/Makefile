# $NetBSD: Makefile,v 1.2 2011/11/17 19:26:42 ryoon Exp $
#

DISTNAME=	roboto-fonts-20111115a
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://source.android.com/
COMMENT=	Roboto font family from Google's Android 4
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

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
