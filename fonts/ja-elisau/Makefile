# $NetBSD: Makefile,v 1.17 2012/10/03 18:28:24 asau Exp $

DISTNAME=		elisau10
PKGNAME=		ja-elisau-1.0
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://www.wheel.gr.jp/~dai/software/ \
			ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} clR5x8.bdf

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.wheel.gr.jp/~dai/software/#elisau10
COMMENT=		10x8 dots X11 bitmap font for JIS X 0208
LICENSE=		no-commercial-use

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES.elisau10${EXTRACT_SUFX}=	\
			http://hp.vector.co.jp/authors/VA004814/freesoft/
SITES.clR5x8.bdf=	ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/

WRKSRC=			${WRKDIR}
USE_TOOLS+=		bdftopcf gzip patch
USE_X11BASE=		YES
DOCDIR=			${PREFIX}/share/doc/elisau
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}
DISTPATCH=		${WRKSRC}/clR5x8-s5x8.diff

post-extract:
	${CP} ${DISTDIR}/clR5x8.bdf ${WRKDIR}; \
	cd ${WRKSRC}; \
	${PATCH} -s < ${DISTPATCH}

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		${TOOLS_PATH.bdftopcf} -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${WRKSRC}/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
