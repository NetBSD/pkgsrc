# $NetBSD: Makefile,v 1.5 2024/03/24 13:06:01 adam Exp $

DISTNAME=	cyclonedx_bom-4.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-bom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python
COMMENT=	Creates CycloneDX Software Bill of Materials for Python projects
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.1:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib>=6.1.0:../../security/py-cyclonedx-python-lib
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.11:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-packaging>=22:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-requirements-parser>=32.0:../../devel/py-pip-requirements-parser

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cyclonedx-py cyclonedx-py-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
