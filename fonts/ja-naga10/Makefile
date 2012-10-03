# $NetBSD: Makefile,v 1.11 2012/10/03 18:28:24 asau Exp $

DISTNAME=		knj10-1.1
PKGNAME=		ja-naga10-1.1
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://hp.vector.co.jp/authors/VA013391/fonts/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			6x12${EXTRACT_SUFX}

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://hp.vector.co.jp/authors/VA013391/fonts/#naga10
COMMENT=		10x10 dots X11 bitmap font for JIS X 0208

USE_X11BASE=		YES
USE_TOOLS+=		bdftopcf gzip patch
DOCDIR=			${PREFIX}/share/doc
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/local share/doc

post-extract:
	cd ${WRKDIR}; \
	${MV} ${DISTNAME}/README ${DISTNAME}/README.naga10; \
	${MV} 6x12/README 6x12/README.6x12; \
	${MV} 6x12/* ${DISTNAME}/;

pre-patch:
	cd ${WRKSRC}; \
	for i in min10 maru10; do \
		${PATCH} -s -o $$i.bdf < $$i.bdf.diff; \
	done;

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		bdftopcf $$i | ${GZIP_CMD} > $$p.gz; \
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
