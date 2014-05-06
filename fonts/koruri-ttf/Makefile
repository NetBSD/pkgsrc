# $NetBSD: Makefile,v 1.1 2014/05/06 13:16:18 ryoon Exp $
#

DISTNAME=	Koruri-${KORURI_VERSION}
PKGNAME=	koruri-ttf-${KORURI_VERSION}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=koruri/60791/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	http://koruri.lindwurm.biz/
COMMENT=	Koruri Japanese TrueType fonts
LICENSE=	apache-2.0

KORURI_VERSION=	20140319

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			share/doc/${PKGBASE}

INSTALL_FONTS=	Koruri-Bold.ttf \
		Koruri-Extrabold.ttf \
		Koruri-Light.ttf \
		Koruri-Regular.ttf \
		Koruri-Semibold.ttf
INSTALL_DOCS=	LICENSE.txt \
		README.md

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
