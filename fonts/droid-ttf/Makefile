# $NetBSD: Makefile,v 1.3 2012/10/03 18:28:18 asau Exp $
#

DISTNAME=	droid-fonts-20111115
PKGNAME=	${DISTNAME:S/fonts/ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://android.git.kernel.org/?p=platform/frameworks/base.git;a=tree;f=data/fonts
COMMENT=	The Droid fonts family from Ascender Corporation
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

INSTALL_FONTS=	DroidKufi-Bold.ttf \
		DroidKufi-Regular.ttf \
		DroidNaskh-Bold.ttf \
		DroidNaskh-Regular.ttf \
		DroidSans-Bold.ttf \
		DroidSans.ttf \
		DroidSansArmenian.ttf \
		DroidSansEthiopic-Bold.ttf \
		DroidSansEthiopic-Regular.ttf \
		DroidSansFallback.ttf \
		DroidSansFallbackFull.ttf \
		DroidSansFallbackLegacy.ttf \
		DroidSansGeorgian.ttf \
		DroidSansHebrew-Bold.ttf \
		DroidSansHebrew-Regular.ttf \
		DroidSansJapanese.ttf \
		DroidSansMono.ttf \
		DroidSansThai.ttf \
		DroidSerif-Bold.ttf \
		DroidSerif-BoldItalic.ttf \
		DroidSerif-Italic.ttf \
		DroidSerif-Regular.ttf
INSTALL_DOCS=	NOTICE

do-install:
.for filename in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${FONTDIR}
.endfor
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
