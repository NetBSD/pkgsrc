# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:38:32 kei Exp $

DISTNAME=		kaname_k12_bdf
PKGNAME=		ja-kaname-0.0.0.20030112
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL} # original site was closed.

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
COMMENT=		12x12 dots X11 bitmap font for JIS X 0208

USE_X11BASE=		YES
DOCDIR=			${PREFIX}/share/doc/kaname
FONTDIR=		${X11PREFIX}/lib/X11/fonts/local
WRKSRC=			${WRKDIR}

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

post-install:
	cd ${FONTDIR}; \
	mkfontdir

post-deinstall:
	cd ${FONTDIR}; \
	mkfontdir

.include "../../mk/bsd.pkg.mk"
