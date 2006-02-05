# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:09 joerg Exp $

DISTNAME=		kaname_k12_bdf
PKGNAME=		ja-kaname-0.0.0.20030112
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL} # original site was closed.

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
COMMENT=		12x12 dots X11 bitmap font for JIS X 0208

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
USE_TOOLS+=		bdftopcf gzip
DOCDIR=			${PREFIX}/share/doc/kaname
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}

#LICENSE=		no-commercial-use

do-build:
	cd ${WRKSRC}; \
	for i in *.bdf; do \
		p=`basename $$i .bdf`.pcf; \
		bdftopcf -o $$p $$i; \
		${GZIP_CMD} -c $$p > $$p.gz; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}; \
	${INSTALL_DATA} ${WRKSRC}/readme.kaname_bdf ${DOCDIR}; \
	${INSTALL_DATA} ${WRKSRC}/doc.orig/* ${DOCDIR}; \
	${INSTALL_DATA_DIR} ${FONTDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${FONTDIR}

.include "../../mk/bsd.pkg.mk"
