# $NetBSD: Makefile,v 1.14 2012/10/03 18:28:24 asau Exp $

DISTNAME=		kaname_k12_bdf
PKGNAME=		ja-kaname-0.0.0.20030112
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL} # original site was closed.

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
COMMENT=		12x12 dots X11 bitmap font for JIS X 0208
#LICENSE=		no-commercial-use

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
USE_TOOLS+=		bdftopcf gzip
DOCDIR=			${PREFIX}/share/doc/kaname
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		${TOOLS_PATH.bdftopcf} -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.kaname_bdf ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.orig/* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
