# $NetBSD: Makefile,v 1.1 2016/05/02 15:46:28 nonaka Exp $
#

DISTNAME=	Ohruri-${OHRURI_VERSION}
PKGNAME=	ohruri-ttf-${OHRURI_VERSION}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=koruri/63358/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	http://koruri.lindwurm.biz/
COMMENT=	Ohruri Japanese TrueType fonts
LICENSE=	apache-2.0

OHRURI_VERSION=	20150606

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			share/doc/${PKGBASE}

INSTALL_FONTS=	Ohruri-Bold.ttf \
		Ohruri-Extrabold.ttf \
		Ohruri-Light.ttf \
		Ohruri-Regular.ttf \
		Ohruri-Semibold.ttf
INSTALL_DOCS=	LICENSE \
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
