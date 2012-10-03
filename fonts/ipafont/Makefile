# $NetBSD: Makefile,v 1.5 2012/10/03 18:28:24 asau Exp $
#

DISTNAME=	IPAfont00303
PKGNAME=	${DISTNAME:S/IPAfont/ipafont-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ossipedia.ipa.go.jp/ipafont/
COMMENT=	IPA JIS X 0213 fonts (Gothic, P Gothic, Mincho, and P Mincho)
LICENSE=	ipafont

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
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
