# $NetBSD: Makefile,v 1.8 2015/07/04 16:18:31 joerg Exp $
#

DISTNAME=	IPAfont00303
PKGNAME=	${DISTNAME:S/IPAfont/ipafont-/}
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	http://dl.ipafont.ipa.go.jp/IPAfont/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ipafont.ipa.go.jp/
COMMENT=	IPA JIS X 0213 fonts (Gothic, P Gothic, Mincho, and P Mincho)
LICENSE=	ipafont

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	ipag.ttf \
		ipagp.ttf \
		ipam.ttf \
		ipamp.ttf
INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_IPAfont00303.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
