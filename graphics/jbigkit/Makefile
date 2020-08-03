# $NetBSD: Makefile,v 1.9 2020/08/03 21:34:06 wiz Exp $

DISTNAME=	jbigkit-2.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/jbigkit/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cl.cam.ac.uk/~mgk25/jbigkit/
COMMENT=	JBIG-KIT lossless image compression library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	test

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
