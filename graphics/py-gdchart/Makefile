# $NetBSD: Makefile,v 1.3 2001/12/08 11:09:52 jmc Exp $
#

DISTNAME=	gdchart-py-0.6
PKGNAME=	py-gdchart-0.6
CATEGORIES=	graphics python
MASTER_SITES=	http://athani.pair.com/msteed/software/gdchart/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://athani.pair.com/msteed/software/gdchart/
COMMENT=	Python interface to GDChart

BUILD_DEPENDS=	gdchart-0.10.1*:../../graphics/gdchart

USE_GMAKE=	yes
PYTHON_VERSIONS_ACCEPTED	=20
MAKE_ENV=	GD_INCLUDE=${LOCALBASE}/include \
		GDCHART_INCLUDE=${LOCALBASE}/include \
		PYTHON_INCLUDE=${LOCALBASE}/include/python2.0 \
		LOCALBASE=${LOCALBASE}
PLIST_SUBST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g} \
		EXAMPLE_DIR=${EXAMPLE_DIR:S/^${LOCALBASE}\///g}
MODULE_FILES=	chart.py gdchart.so
EXAMPLE_FILES=	test.html test.py CHANGES
EXAMPLE_DIR=	${PREFIX}/share/examples/py-gdchart

do-install:
.for f in ${MODULE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/python2.0/site-packages
.endfor
.if !defined(NO_PKGDOCS)
	#${MKDIR} ${EXAMPLE_DIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-gdchart
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLE_DIR}
.endfor
.endif

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
