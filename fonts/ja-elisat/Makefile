# $NetBSD: Makefile,v 1.15 2012/10/03 18:28:24 asau Exp $

DISTNAME=		elisat10
PKGNAME=		ja-elisat-1.0
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=	${MASTER_SITE_FREEBSD}	
MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.tea.forus.or.jp/toshi/exhibition/elisat10.html
COMMENT=		8x8 dots X11 bitmap font for JIS X 0208
LICENSE=		no-commercial-use

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
DOCDIR=			${PREFIX}/share/doc/elisat
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}
USE_TOOLS+=		bdftopcf gzip

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		${TOOLS_PATH.bdftopcf} -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${WRKSRC}/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
