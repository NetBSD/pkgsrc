# $NetBSD: Makefile,v 1.16 2023/11/10 18:54:09 adam Exp $

DISTNAME=	asdf-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asdf-format/asdf
COMMENT=	Advanced Scientific Data Format
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.0.1:../../math/py-asdf-standard
DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.3:../../math/py-asdf-transform-schemas
DEPENDS+=	${PYPKGPREFIX}-asdf-unit-schemas>=0.1:../../math/py-asdf-unit-schemas
DEPENDS+=	${PYPKGPREFIX}-attrs>=20.1.0":../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.11.4:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.6.2:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.22:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=19:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-fsspec>=2022.8.2:../../sysutils/py-fsspec
TEST_DEPENDS+=	${PYPKGPREFIX}-lz4>=0.10:../../archivers/py-lz4
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus-[0-9]*:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata-[0-9]*:../../net/py-test-remotedata

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	asdf/_jsonschema/json/bin/jsonschema_suite
REPLACE_PYTHON+=	asdf/extern/RangeHTTPServer.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} asdftool asdftool-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
