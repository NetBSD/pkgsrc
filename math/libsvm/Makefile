# $NetBSD: Makefile,v 1.2 2014/10/19 08:59:31 cheusov Exp $
#

DISTNAME=	libsvm-3.18
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/
COMMENT=	Library for Support Vector Machines
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

BUILD_TARGET=	all lib
AUTO_MKDIRS=	yes

REPLACE_PYTHON=		tools/*.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libsvm.so.2 ${DESTDIR}${PREFIX}/lib
	${LN} -s libsvm.so.2 ${DESTDIR}${PREFIX}/lib/libsvm.so
	${INSTALL_DATA} ${WRKSRC}/svm.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/FAQ.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/tools/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README_tools
	${INSTALL_DATA} ${WRKSRC}/heart_scale \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/grid.py ${DESTDIR}${PREFIX}/bin/svm-grid
	${INSTALL_SCRIPT} ${WRKSRC}/tools/easy.py ${DESTDIR}${PREFIX}/bin/svm-easy
	${INSTALL_SCRIPT} ${WRKSRC}/tools/checkdata.py ${DESTDIR}${PREFIX}/bin/svm-checkdata
	${INSTALL_SCRIPT} ${WRKSRC}/tools/subset.py ${DESTDIR}${PREFIX}/bin/svm-subset

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
