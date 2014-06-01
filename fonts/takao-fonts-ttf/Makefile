# $NetBSD: Makefile,v 1.5 2014/06/01 16:35:37 wiz Exp $
#

DISTNAME=	takao-fonts-ttf-003.02.01
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	http://launchpad.net/takao-fonts/003.02/003.02.01/+download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://launchpad.net/takao-fonts
COMMENT=	Takao fonts are based on IPA(ex) fonts, and includes some bug fix
LICENSE=	ipafont

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	TakaoExGothic.ttf \
		TakaoExMincho.ttf \
		TakaoGothic.ttf \
		TakaoMincho.ttf \
		TakaoPGothic.ttf \
		TakaoPMincho.ttf
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
