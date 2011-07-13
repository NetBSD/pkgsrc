# $NetBSD: Makefile,v 1.2 2011/07/13 12:00:03 ryoon Exp $
#

DISTNAME=	# empty
PKGNAME=	migu-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mix-mplus-ipa/52283/}
DISTFILES=	Migu-1P-${VERSION}.zip \
		Migu-1C-${VERSION}.zip \
		Migu-1M-${VERSION}.zip \
		Migu-2M-${VERSION}.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mix-mplus-ipa.sourceforge.jp/
COMMENT=	Fonts generated from M+ and IPA Gothic (Universal Design)
LICENSE=	ipafont AND mplusfont

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

VERSION=	20110610

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

INSTALL_FONTS=	Migu-1C-${VERSION}/Migu-1C-bold.ttf \
		Migu-1C-${VERSION}/Migu-1C-regular.ttf \
		Migu-1M-${VERSION}/Migu-1M-bold.ttf \
		Migu-1M-${VERSION}/Migu-1M-regular.ttf \
		Migu-2M-${VERSION}/Migu-2M-bold.ttf \
		Migu-2M-${VERSION}/Migu-2M-regular.ttf \
		Migu-1P-${VERSION}/Migu-1P-bold.ttf \
		Migu-1P-${VERSION}/Migu-1P-regular.ttf

INSTALL_DOCS=	Migu-1C-${VERSION}/Migu-README.txt \
		Migu-1C-${VERSION}/ipag00303/IPA_Font_License_Agreement_v1.0.txt \
		Migu-1C-${VERSION}/mplus-TESTFLIGHT-040/LICENSE_E

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
