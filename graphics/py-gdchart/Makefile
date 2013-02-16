# $NetBSD: Makefile,v 1.32 2013/02/16 11:22:24 wiz Exp $
#

DISTNAME=	gdchart-py-0.6
PKGNAME=	${PYPKGPREFIX}-gdchart-0.6
PKGREVISION=	12
CATEGORIES=	graphics python
MASTER_SITES=	http://www.nullcube.com/software/pygdchart.html

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://athani.pair.com/msteed/software/gdchart/
COMMENT=	Python interface to GDChart

USE_TOOLS+=	gmake
MAKE_ENV+=	GD_INCLUDE=${LOCALBASE}/include \
		GDCHART_INCLUDE=${LOCALBASE}/include \
		PYTHON_INCLUDE=${LOCALBASE}/${PYINC} \
		HAVE_LIBFREETYPE=1 \
		LOCALBASE=${LOCALBASE:Q}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
MODULE_FILES=	chart.py gdchart.so
EXAMPLE_FILES=	test.html test.py CHANGES
EXAMPLE_DIR=	${PREFIX}/share/examples/${PYPKGPREFIX}-gdchart
PY_PATCHPLIST=	yes

INSTALLATION_DIRS=	${PYSITELIB:S/^${PREFIX}\///}

do-install:
.for f in ${MODULE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PYSITELIB}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLE_DIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EXAMPLE_DIR}
.endfor

.include "../../graphics/gdchart/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
