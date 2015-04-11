# $NetBSD: Makefile,v 1.4 2015/04/11 03:25:43 rodent Exp $
#

DISTNAME=	libsvm-3.20
CATEGORIES=	math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/
COMMENT=	Library for Support Vector Machines
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_TARGET=	all lib
AUTO_MKDIRS=	yes

REPLACE_PYTHON=		tools/*.py

SUBST_CLASSES+=         paths
SUBST_SED.paths=	-e 's,[.][.]/svm-train,${PREFIX}/bin/svm-train,'
SUBST_SED.paths+=	-e 's,[.][.]/svm-scale,${PREFIX}/bin/svm-scale,'
SUBST_SED.paths+=	-e 's,[.][.]/svm-predict,${PREFIX}/bin/svm-predict,'
SUBST_SED.paths+=	-e 's,"[.]/grid[.]py,"${PREFIX}/bin/svm-grid,'
SUBST_SED.paths+=	-e 's,/usr/bin/gnuplot,${PREFIX}/bin/gnuplot,'
SUBST_FILES.paths=	tools/grid.py tools/easy.py
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

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
