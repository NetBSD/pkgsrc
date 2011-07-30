# $NetBSD: Makefile,v 1.2 2011/07/30 12:32:14 ryoon Exp $
#

DISTNAME=	KanjiStrokeOrders_v${KSOVER}
PKGNAME=	${DISTNAME:tl:S/_v/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://sites.google.com/site/nihilistorguk/Home/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sites.google.com/site/nihilistorguk/
COMMENT=	Japanese Kanji characters stroke order font
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

KSOVER=		2.016

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	KanjiStrokeOrders_v${KSOVER}.ttf
INSTALL_DOCS=	KSO_Excel_Sample.pdf \
		KSO_PPT_Sample.pdf \
		copyright.txt \
		readme_en_v${KSOVER}.txt

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
