# $NetBSD: Makefile,v 1.7 2002/09/21 23:46:50 jlam Exp $
#

DISTNAME=	gdchart-py-0.6
PKGNAME=	${PYPKGPREFIX}-gdchart-0.6
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://athani.pair.com/msteed/software/gdchart/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://athani.pair.com/msteed/software/gdchart/
COMMENT=	Python interface to GDChart

BUILD_DEPENDS=	gdchart-0.10.1*:../../graphics/gdchart

USE_GMAKE=	yes
MAKE_ENV=	GD_INCLUDE=${LOCALBASE}/include \
		GDCHART_INCLUDE=${LOCALBASE}/include \
		PYTHON_INCLUDE=${LOCALBASE}/${PYINC} \
		LOCALBASE=${LOCALBASE}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
MODULE_FILES=	chart.py gdchart.so
EXAMPLE_FILES=	test.html test.py CHANGES
EXAMPLE_DIR=	${PREFIX}/share/examples/${PYPKGPREFIX}-gdchart
PY_PATCHPLIST=	yes
PYBINMODULE=	yes

do-install:
.for f in ${MODULE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${PYSITELIB}
.endfor
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLE_DIR}
.endfor

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
