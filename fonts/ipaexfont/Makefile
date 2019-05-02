# $NetBSD: Makefile,v 1.12 2019/05/02 15:49:16 ryoon Exp $
#

IPAEXVER=	00401
DISTNAME=	IPAexfont${IPAEXVER}
PKGNAME=	${DISTNAME:S/IPAexfont/ipaexfont-/}
CATEGORIES=	fonts japanese
MASTER_SITES+=	https://oscdl.ipa.go.jp/IPAexfont/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ipafont.ipa.go.jp/
COMMENT=	IPAex fonts (fixed JIS X0213 Kanji, and proportional ASCII)
LICENSE=	ipafont

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCSDIR}

INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_IPAexfont${IPAEXVER}.txt

USE_LANGUAGES=	# none

do-install:
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
