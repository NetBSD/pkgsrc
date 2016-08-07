# $NetBSD: Makefile,v 1.6 2016/08/07 10:36:43 wen Exp $

DISTNAME=	obspy-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/obspy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://www.obspy.org/
COMMENT=	Python framework for seismological observatories
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-suds>=0.4:../../net/py-suds
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-future>=0.12.4:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0:../../databases/py-sqlalchemy

USE_LANGUAGES=	c fortran
USE_TOOLS+=	bash:run

REPLACE_BASH=	obspy/taup/tests/data/TauP_test_data/gendata.sh

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-suds

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
