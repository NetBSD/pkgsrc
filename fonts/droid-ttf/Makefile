# $NetBSD: Makefile,v 1.1.1.1 2011/04/25 13:37:00 ryoon Exp $
#

DISTNAME=	droid-fonts-20100923
PKGNAME=	${DISTNAME:S/fonts/ttf/}
CATEGORIES=	fonts
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://android.git.kernel.org/?p=platform/frameworks/base.git;a=tree;f=data/fonts
COMMENT=	The Droid fonts family from Ascender Corporation
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

INSTALL_FONTS=	DroidSans-Bold.ttf \
		DroidSans.ttf \
		DroidSansArabic.ttf \
		DroidSansFallback.ttf \
		DroidSansFallbackLegacy.ttf \
		DroidSansHebrew.ttf \
		DroidSansJapanese.ttf \
		DroidSansMono.ttf \
		DroidSansThai.ttf \
		DroidSerif-Bold.ttf \
		DroidSerif-BoldItalic.ttf \
		DroidSerif-Italic.ttf \
		DroidSerif-Regular.ttf
INSTALL_DOCS=	NOTICE \
		README.txt

do-install:
.for filename in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${FONTDIR}
.endfor
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
