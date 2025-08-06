# $NetBSD: Makefile,v 1.10 2025/08/06 15:33:25 ryoon Exp $

DISTNAME=	KanjiStrokeOrders-${KSOVER}
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	-https://drive.google.com/uc?export=download&id=1DKZEYA3PJ8ulLnjYDP5bxzJ3SWi59ghr
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://kanji.uk/
COMMENT=	Japanese Kanji characters stroke order font
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
NO_CONFIGURE=	YES
NO_BUILD=	YES

KSOVER=		4.005

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	KanjiStrokeOrders_v${KSOVER}.ttf
INSTALL_DOCS=	KSO_Excel_Sample.pdf \
		KSO_PPT_Sample.pdf \
		LICENCE.txt \
		README_en_v${KSOVER}.txt

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
