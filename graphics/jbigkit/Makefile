# $NetBSD: Makefile,v 1.1.1.1 2010/01/21 12:35:31 obache Exp $
#

DISTNAME=	jbigkit-2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cl.cam.ac.uk/~mgk25/jbigkit/
COMMENT=	JBIG-KIT lossless image compression library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

WRKSRC=	${WRKDIR}/jbigkit

TEST_TARGET=	test

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc/jbig

do-install:
	${RUN} \
	cd ${WRKSRC}/libjbig; \
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
