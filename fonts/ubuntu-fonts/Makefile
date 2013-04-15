# $NetBSD: Makefile,v 1.1 2013/04/15 17:22:40 uwe Exp $

VERSION=	0.80
PKGNAME=	ubuntu-fonts-${VERSION}
CATEGORIES=	fonts
DISTNAME=	ubuntu-font-family-${VERSION}
EXTRACT_SUFX=	.zip
MASTER_SITES=	http://font.ubuntu.com/download/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://font.ubuntu.com/
COMMENT=	TrueType font family from Ubuntu
LICENSE=	ubuntu-font-license

NO_CONFIGURE=	yes
NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

INSTALL_FONTS=	Ubuntu-B.ttf			\
		Ubuntu-BI.ttf			\
		Ubuntu-C.ttf			\
		Ubuntu-L.ttf			\
		Ubuntu-LI.ttf			\
		Ubuntu-M.ttf			\
		Ubuntu-MI.ttf			\
		Ubuntu-R.ttf			\
		Ubuntu-RI.ttf			\
		UbuntuMono-B.ttf		\
		UbuntuMono-BI.ttf		\
		UbuntuMono-R.ttf		\
		UbuntuMono-RI.ttf

INSTALL_DOCS=	CONTRIBUTING.txt		\
		FONTLOG.txt			\
		LICENCE-FAQ.txt			\
		LICENCE.txt			\
		README.txt			\
		TRADEMARKS.txt			\
		copyright.txt

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
