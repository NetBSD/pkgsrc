# $NetBSD: Makefile,v 1.8 2004/03/31 10:23:59 grant Exp $
#

DISTNAME=	jisx0213fonts-0.0
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/
DISTFILES=	${FONTS:C/$/.bdf.gz/}

MAINTAINER=	itojun@itojun.org, uebayasi@NetBSD.org
HOMEPAGE=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/
COMMENT=	X11 bitmap fonts for JIS X 0213

USE_X11BASE=	yes

FONTS=		K14-1 K14-2 jiskan16-2000-1 jiskan16-2000-2
FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_X11_DIRS=	${FONTDIR}

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
	@${INSTALL_DATA_DIR} ${FONTDIR}
	@for f in ${FONTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f}.pcf.gz ${FONTDIR}; \
	done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
