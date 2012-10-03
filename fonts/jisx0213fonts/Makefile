# $NetBSD: Makefile,v 1.15 2012/10/03 18:28:25 asau Exp $
#

DISTNAME=	jisx0213fonts-0.0
PKGREVISION=	1
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/
DISTFILES=	${FONTS:C/$/.bdf.gz/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/
COMMENT=	X11 bitmap fonts for JIS X 0213

USE_X11BASE=	yes
USE_TOOLS+=	gzip

FONTS=		K14-1 K14-2 jiskan16-2000-1 jiskan16-2000-2
FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=	${FONTDIR}

WRKSRC=		${WRKDIR}

do-extract:
	@for f in ${FONTS}; do \
		${GZCAT} ${DISTDIR}/$${f}.bdf.gz >${WRKSRC}/$${f}.bdf; \
	done

do-build:
	@cd ${WRKSRC}; \
	for f in ${FONTS}; do \
		${X11BASE}/bin/bdftopcf $${f}.bdf | \
		${GZIP_CMD} -c >$${f}.pcf.gz; \
	done

do-install:
	@${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	@for f in ${FONTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f}.pcf.gz ${DESTDIR}${FONTDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
