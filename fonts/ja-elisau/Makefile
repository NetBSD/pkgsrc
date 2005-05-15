# $NetBSD: Makefile,v 1.6 2005/05/15 22:02:27 jlam Exp $

DISTNAME=		elisau10
PKGNAME=		ja-elisau-1.0
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://www.wheel.gr.jp/~dai/software/ \
			ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} clR5x8.bdf

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.wheel.gr.jp/~dai/software/#elisau10
COMMENT=		10x8 dots X11 bitmap font for JIS X 0208

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES_elisau10${EXTRACT_SUFX}=	\
			http://hp.vector.co.jp/authors/VA004814/freesoft/
SITES_clR5x8.bdf=	ftp://ftp.jp.NetBSD.org/pub/NetBSD-jp/tut-jp/fonts/

WRKSRC=			${WRKDIR}
USE_GNU_TOOLS+=		patch
PKGSRC_USE_TOOLS+=	gzip
USE_X11BASE=		YES
DOCDIR=			${PREFIX}/share/doc/elisau
FONTDIR=		${X11PREFIX}/lib/X11/fonts/local
DISTPATCH=		${WRKSRC}/clR5x8-s5x8.diff

LICENSE=		no-commercial-use

post-extract:
	${CP} ${DISTDIR}/clR5x8.bdf ${WRKDIR}; \
	cd ${WRKSRC}; \
	${PATCH} -s < ${DISTPATCH}

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		bdftopcf -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.doc ${WRKSRC}/*.txt ${DOCDIR}; \
	${INSTALL_DATA_DIR} ${FONTDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${FONTDIR}

post-install:
	cd ${FONTDIR}; \
	mkfontdir

post-deinstall:
	cd ${FONTDIR}; \
	mkfontdir

.include "../../mk/bsd.pkg.mk"
