# $NetBSD: Makefile,v 1.4 2013/08/04 09:22:25 adam Exp $

DISTNAME=	jbigkit-2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cl.cam.ac.uk/~mgk25/jbigkit/
COMMENT=	JBIG-KIT lossless image compression library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/jbigkit

TEST_TARGET=	test

CFLAGS+=	-I../libjbig
MAKEFLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc/jbig

do-install:
	${RUN} cd ${WRKSRC}/libjbig; \
	for h in *.h; do \
		${INSTALL_DATA} "$${h}" ${DESTDIR}${PREFIX}/include; \
	done; \
	for l in *.la; do \
		${LIBTOOL} --mode=install ${INSTALL_LIB} "$${l}" \
			${DESTDIR}${PREFIX}/lib; \
	done; \
	for t in *.txt; do \
		${INSTALL_DATA} "$${t}" ${DESTDIR}${PREFIX}/share/doc/jbig; \
	done; \
	cd ${WRKSRC}/pbmtools; \
	for p in jbgtopbm jbgtopbm85 pbmtojbg pbmtojbg85; do \
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM} "$${p}" \
			${DESTDIR}${PREFIX}/bin; \
	done; \
	for m in *.1; do \
		${INSTALL_MAN} "$${m}" ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done;

.include "../../mk/bsd.pkg.mk"
