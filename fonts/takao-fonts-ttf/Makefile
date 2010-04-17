# $NetBSD: Makefile,v 1.1.1.1 2010/04/17 09:20:56 obache Exp $
#

DISTNAME=	takao-fonts-ttf-003.02.01
CATEGORIES=	fonts japanese
MASTER_SITES=	http://launchpad.net/takao-fonts/003.02/003.02.01/+download/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	https://launchpad.net/takao-fonts
COMMENT=	Takao fonts are based on IPA(ex) fonts, and includes some bug fix
# LICENSE=	IPA Font License Agreement v1.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
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
