# $NetBSD: Makefile,v 1.8 2015/07/04 16:18:32 joerg Exp $

DISTNAME=	KanjiStrokeOrders_v${KSOVER}
PKGNAME=	${DISTNAME:tl:S/_v/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	https://dl.dropboxusercontent.com/u/39004158/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/nihilistorguk/
COMMENT=	Japanese Kanji characters stroke order font
LICENSE=	modified-bsd

NO_CONFIGURE=	YES
NO_BUILD=	YES

KSOVER=		3.001

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	KanjiStrokeOrders_v${KSOVER}.ttf
INSTALL_DOCS=	KSO_Excel_Sample.pdf \
		KSO_PPT_Sample.pdf \
		copyright.txt \
		readme_en_v${KSOVER}.utf

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
