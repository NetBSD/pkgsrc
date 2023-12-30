# $NetBSD: Makefile,v 1.11 2023/12/30 16:55:21 zafer Exp $

DISTNAME=		misaki_bdf_2012-06-03
PKGNAME=		${DISTNAME:S/-//g:S/misaki_bdf_/misaki-fonts-1.0./}
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		https://www.aydogan.net/distfiles/fonts/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20121008163534/http://www.geocities.jp/littlimi/misaki.htm
COMMENT=		8x8 dots X11 bitmap font for JIS X 0208
LICENSE=		mplusfont

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES
USE_TOOLS+=		bdftopcf gzip

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=		${PREFIX}/share/fonts/X11/local
FONTS_DIRS.x11=		${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/local \
			${DOCSDIR}

INSTALL_FONTS=		misaki_gothic.bdf \
			misaki_mincho.bdf \
			misaki_4x8_iso8859.bdf \
			misaki_4x8_jisx0201.bdf
INSTALL_DOCS=		misaki.txt \
			readme.txt

do-build:
.for filename in ${INSTALL_FONTS}
	bdftopcf -o ${WRKSRC}/${filename:S/bdf/pcf/} ${WRKSRC}/${filename}
	${GZIP_CMD} ${WRKSRC}/${filename:S/bdf/pcf/}
.endfor

do-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor
.for filename in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${filename:S/bdf/pcf.gz/} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
