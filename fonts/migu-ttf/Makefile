# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:27 asau Exp $
#

DISTNAME=	# empty
PKGNAME=	migu-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mix-mplus-ipa/53389/}
DISTFILES=	migu-1p-${VERSION}.zip \
		migu-1c-${VERSION}.zip \
		migu-1m-${VERSION}.zip \
		migu-2m-${VERSION}.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mix-mplus-ipa.sourceforge.jp/
COMMENT=	Fonts generated from M+ and IPA Gothic (Universal Design)
LICENSE=	ipafont AND mplusfont

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

VERSION=	20111002

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

INSTALL_FONTS=	migu-1c-${VERSION}/migu-1c-bold.ttf \
		migu-1c-${VERSION}/migu-1c-regular.ttf \
		migu-1m-${VERSION}/migu-1m-bold.ttf \
		migu-1m-${VERSION}/migu-1m-regular.ttf \
		migu-2m-${VERSION}/migu-2m-bold.ttf \
		migu-2m-${VERSION}/migu-2m-regular.ttf \
		migu-1p-${VERSION}/migu-1p-bold.ttf \
		migu-1p-${VERSION}/migu-1p-regular.ttf

INSTALL_DOCS=	migu-1c-${VERSION}/migu-README.txt \
		migu-1c-${VERSION}/ipag00303/IPA_Font_License_Agreement_v1.0.txt \
		migu-1c-${VERSION}/mplus-TESTFLIGHT-043/LICENSE_E

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
