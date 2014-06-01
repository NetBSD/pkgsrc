# $NetBSD: Makefile,v 1.6 2014/06/01 16:35:35 wiz Exp $

DISTNAME=	KanjiStrokeOrders_v${KSOVER}
PKGNAME=	${DISTNAME:tl:S/_v/-ttf-/}
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	https://sites.google.com/site/nihilistorguk/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/nihilistorguk/
COMMENT=	Japanese Kanji characters stroke order font
LICENSE=	modified-bsd

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

KSOVER=		3.000

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
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
