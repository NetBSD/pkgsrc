# $NetBSD: Makefile,v 1.4 2015/07/04 16:18:32 joerg Exp $
#

DISTNAME=	Konatu_ver_26
PKGNAME=	${DISTNAME:tl:S/_ver_/-ttf-/}
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.masuseki.com/be/konatu/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.masuseki.com/?u=be/konatu.htm
COMMENT=	Japanese TrueType gothic (sans-serif) fonts, Konatu fonts
LICENSE=	cc-by-sa-v3.0

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

INSTALL_FONTS=	Konatu.ttf \
		KonatuTohaba.ttf

INSTALL_DOCS=	README.txt \
		README_Japanese.txt

USE_LANGUAGES=	# none

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
