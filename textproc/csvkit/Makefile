# $NetBSD: Makefile,v 1.2 2015/01/11 13:52:42 cheusov Exp $

DISTNAME=	0.9.0
PKGNAME=	csvkit-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/onyxfish/csvkit/archive/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/onyxfish/csvkit/archive/
COMMENT=	Suite of utilities for converting to and working with CSV
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-xlrd>=0.9.2:../../textproc/py-xlrd
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.7:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-coverage>=1.0.7:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=2.0.3:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-jdcal>=0.9.3:../../time/py-jdcal
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.6.3:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
#DEPENDS+=		${PYPKGPREFIX}-tox>=1.3:../../*/py-tox

PYTHON_VERSIONS_INCOMPATIBLE=	26

# csvkit publishes files like "0.9.0.tar.gz"
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none

EGG_NAME=	${PKGNAME}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.if ${PYPKGPREFIX} == "py26"
DEPENDS+=	${PYPKGPREFIX}-ordereddict>=1.1:../../devel/py-ordereddict
.endif
.include "../../mk/bsd.pkg.mk"
