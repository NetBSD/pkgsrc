# $NetBSD: Makefile,v 1.26 2024/03/06 21:07:39 wiz Exp $

DISTNAME=	obspy-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/obspy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.obspy.org/
COMMENT=	Python framework for seismological observatories
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.20:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.7:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-proj>=0:../../geography/py-proj
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-json-report>=0:../../devel/py-json-report

USE_LANGUAGES=	c fortran
USE_TOOLS+=	bash:run

REPLACE_BASH=	obspy/taup/tests/data/TauP_test_data/gendata.sh

PYTHON_VERSIONS_INCOMPATIBLE=	27 38
PYTHON_SELF_CONFLICT=		yes

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
