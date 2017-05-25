# $NetBSD: Makefile,v 1.3 2017/05/25 03:55:24 soda Exp $
#

DISTNAME=	TakaoExFonts_00201.01
PKGNAME=	takao-ex-fonts-ttf-002.01.01
CATEGORIES=	fonts japanese
MASTER_SITES=	https://launchpad.net/takao-fonts/trunk/15.03/+download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://launchpad.net/takao-fonts
COMMENT=	Takao Ex Fonts are based on IPA Ex fonts, and includes some bug fix
LICENSE=	ipafont

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	TakaoExGothic.ttf \
		TakaoExMincho.ttf
INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		README \
		README.ja \
		ChangeLog

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
