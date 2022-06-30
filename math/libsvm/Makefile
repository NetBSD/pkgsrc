# $NetBSD: Makefile,v 1.12 2022/06/30 11:18:36 nia Exp $

DISTNAME=	libsvm-3.24
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.csie.ntu.edu.tw/~cjlin/libsvm/
COMMENT=	Library for Support Vector Machines
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_TARGET=	all lib
AUTO_MKDIRS=	yes

REPLACE_PYTHON=		tools/*.py

SUBST_CLASSES+=		paths
SUBST_SED.paths=	-e 's,[.][.]/svm-train,${PREFIX}/bin/svm-train,'
SUBST_SED.paths+=	-e 's,[.][.]/svm-scale,${PREFIX}/bin/svm-scale,'
SUBST_SED.paths+=	-e 's,[.][.]/svm-predict,${PREFIX}/bin/svm-predict,'
SUBST_SED.paths+=	-e 's,"[.]/grid[.]py,"${PREFIX}/bin/svm-grid,'
SUBST_SED.paths+=	-e 's,/usr/bin/gnuplot,${PREFIX}/bin/gnuplot,'
SUBST_FILES.paths=	tools/grid.py tools/easy.py
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

.include "../../mk/bsd.prefs.mk"

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

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/libsvm.so.2 \
		${DESTDIR}${PREFIX}/lib/libsvm.so.2
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
