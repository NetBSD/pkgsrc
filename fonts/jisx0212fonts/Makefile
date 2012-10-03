# $NetBSD: Makefile,v 1.19 2012/10/03 18:28:25 asau Exp $

DISTNAME=	jisx0212fonts-0.0
PKGREVISION=	2
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/ \
		http://www.freebsd.org/~itojun/distfiles/
DISTFILES=	jisksp14.bdf.gz jisksp16-1990.bdf.Z min-1-24.bdf.gz \
		jisksp40.bdf.Z

MAINTAINER=	uebayasi@NetBSD.org
COMMENT=	X11 bitmap fonts for JIS X 0212

USE_X11BASE=	yes

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	${DISTFILES}

FONTS=		${DISTFILES:C/\.bdf.*$//}
FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=	${FONTDIR}

USE_TOOLS+=	gzip gunzip

# XXX Can we assume that ${GUNZIP_CMD} can extract .Z files?
do-extract:
	for f in ${DISTFILES}; do \
		gunzip -c ${DISTDIR}/$${f} >${WRKSRC}/$${f%.*}; \
	done

do-build:
	set -e; \
	cd ${WRKSRC}; \
	for f in ${FONTS}; do \
		${X11BASE}/bin/bdftopcf $${f}.bdf | \
		gzip -c >$${f}.pcf.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	set -e; \
	for f in ${FONTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f}.pcf.gz ${DESTDIR}${FONTDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
