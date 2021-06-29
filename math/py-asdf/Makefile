# $NetBSD: Makefile,v 1.3 2021/06/29 08:42:00 nia Exp $

DISTNAME=	asdf-2.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asdf-format/asdf
COMMENT=	Advanced Scientific Data Format
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.2:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-lz4>=0.10:../../archivers/py-lz4
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.10.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	asdf-standard/reference_files/generate/generate
REPLACE_PYTHON+=	asdf/extern/RangeHTTPServer.py

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36	# py-numpy

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} asdftool asdftool-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
