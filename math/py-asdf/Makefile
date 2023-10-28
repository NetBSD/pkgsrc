# $NetBSD: Makefile,v 1.15 2023/10/28 19:57:11 wiz Exp $

DISTNAME=	asdf-2.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.8:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.22:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=19:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml

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
