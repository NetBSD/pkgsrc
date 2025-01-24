# $NetBSD: Makefile,v 1.3 2025/01/24 08:02:28 riastradh Exp $

DISTNAME=	dm-tree-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dm-tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google-deepmind/tree
COMMENT=	Library for working with nested data structures
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-absl-py>=0.6.1:../../devel/py-absl-py
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=18.2.0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.15.4:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.11.2:../../devel/py-wrapt

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c++
USE_TOOLS+=		cmake gmake

SUBST_CLASSES+=		jobs
SUBST_MESSAGE.jobs=	Limit parallelism to MAKE_JOBS
SUBST_STAGE.jobs=	pre-configure
SUBST_FILES.jobs=	setup.py
SUBST_SED.jobs=		-e 's,-j{os.cpu_count()},-j${MAKE_JOBS:U1},'

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
