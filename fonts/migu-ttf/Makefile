# $NetBSD: Makefile,v 1.9 2015/07/04 16:18:32 joerg Exp $
#

DISTNAME=	# empty
PKGNAME=	migu-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_OSDN:=mix-mplus-ipa/59022/}
DISTFILES=	migu-1p-${VERSION}.zip \
		migu-1c-${VERSION}.zip \
		migu-1m-${VERSION}.zip \
		migu-2m-${VERSION}.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mix-mplus-ipa.osdn.jp/
COMMENT=	Fonts generated from M+ and IPA Gothic (Universal Design)
LICENSE=	ipafont

NO_CONFIGURE=	yes
NO_BUILD=	yes

VERSION=	20130617

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
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
		migu-1c-${VERSION}/ipag00303/IPA_Font_License_Agreement_v1.0.txt

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
