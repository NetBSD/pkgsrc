# $NetBSD: Makefile,v 1.11 2005/05/15 22:02:27 jlam Exp $

DISTNAME=	jisx0212fonts-0.0
PKGREVISION=	1
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	ftp://ginkaku.kudpc.kyoto-u.ac.jp/fonts/ \
		ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/ \
		http://www.freebsd.org/~itojun/distfiles/
DISTFILES=	jisksp14.bdf.gz jisksp16-1990.bdf.Z min-1-24.bdf.gz \
		jisksp40.bdf.Z

MAINTAINER=	itojun@itojun.org
COMMENT=	X11 bitmap fonts for JIS X 0212

USE_X11BASE=	yes

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	${DISTFILES}

FONTS=		${DISTFILES:C/\.bdf.*$//}
FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_X11_DIRS=	${FONTDIR}

PKGSRC_USE_TOOLS+=	gzip gunzip

# XXX Can we assume that ${GUNZIP_CMD} can extract .Z files?
do-extract:
	@for f in ${DISTFILES}; do \
		${GUNZIP_CMD} -c ${DISTDIR}/$${f} >${WRKSRC}/$${f%.*}; \
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
