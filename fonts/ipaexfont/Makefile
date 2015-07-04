# $NetBSD: Makefile,v 1.10 2015/07/04 16:18:31 joerg Exp $
#

IPAEXVER=	00201
DISTNAME=	IPAexfont${IPAEXVER}
PKGNAME=	${DISTNAME:S/IPAexfont/ipaexfont-/}
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=ipafonts/57330/} \
		http://dl.ipafont.ipa.go.jp/IPAexfont/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ipafont.ipa.go.jp/
COMMENT=	IPAex fonts (fixed JIS X0213 Kanji, and proportional ASCII)
LICENSE=	ipafont

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	ipaexg.ttf \
		ipaexm.ttf
INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_IPAexfont${IPAEXVER}.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
