# $NetBSD: Makefile,v 1.36 2013/01/07 11:53:11 ryoon Exp $
#

DISTNAME=	ege-umefont_447
PKGNAME=	${DISTNAME:C/([a-z]+)-//:S/_/-ttf-0./}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=ume-font/22212/}
EXTRACT_SUFX=	.7z

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/ume-font/wiki/FrontPage
COMMENT=	Ume 18 Japanese fonts (Mincho and Gothic)
LICENSE=	mplusfont

WRKSRC=		${WRKDIR}/${DISTNAME:C/([a-z]+)-//}

CONFLICTS=	umefont<=0.421
SUPERSEDES=	umefont<=0.421

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	ume-pgc4.ttf \
		ume-pgc5.ttf \
		ume-pgo4.ttf \
		ume-pgo5.ttf \
		ume-pgs4.ttf \
		ume-pgs5.ttf \
		ume-pmo3.ttf \
		ume-pms3.ttf \
		ume-tgc4.ttf \
		ume-tgc5.ttf \
		ume-tgo4.ttf \
		ume-tgo5.ttf \
		ume-tgs4.ttf \
		ume-tgs5.ttf \
		ume-tmo3.ttf \
		ume-tms3.ttf \
		ume-ugo4.ttf \
		ume-ugo5.ttf
INSTALL_DOCS=	license.html

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
