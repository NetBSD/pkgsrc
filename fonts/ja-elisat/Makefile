# $NetBSD: Makefile,v 1.5 2005/05/15 22:02:27 jlam Exp $

DISTNAME=		elisat10
PKGNAME=		ja-elisat-1.0
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://www.tea.forus.or.jp/toshi/exhibition/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		${MASTER_SITES}/elisat10.html
COMMENT=		8x8 dots X11 bitmap font for JIS X 0208

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
DOCDIR=			${PREFIX}/share/doc/elisat
FONTDIR=		${X11PREFIX}/lib/X11/fonts/local
#ALIAS=			${WRKDIR}/fonts.alias
PKGSRC_USE_TOOLS+=	gzip

LICENSE=		no-commercial-use

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		bdftopcf -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.doc ${WRKSRC}/*.html ${DOCDIR}; \
	${INSTALL_DATA_DIR} ${FONTDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${FONTDIR}

post-install:
	cd ${FONTDIR}; \
	mkfontdir

post-deinstall:
	cd ${FONTDIR}; \
	mkfontdir

.include "../../mk/bsd.pkg.mk"
