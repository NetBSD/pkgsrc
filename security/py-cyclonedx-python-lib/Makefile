# $NetBSD: Makefile,v 1.9 2022/07/24 10:55:02 wiz Exp $

DISTNAME=	cyclonedx-python-lib-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-python-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python-lib
COMMENT=	Python library for generating CycloneDX SBOMs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.9:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-setuptools>=47.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.4.0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.0:../../textproc/py-toml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py37"
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.4:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
