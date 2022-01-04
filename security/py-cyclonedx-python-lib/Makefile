# $NetBSD: Makefile,v 1.3 2022/01/04 20:54:40 wiz Exp $

DISTNAME=	cyclonedx-python-lib-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-python-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python-lib
COMMENT=	Python library for generating CycloneDX SBOMs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-packageurl-[0-9]*:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-requirements-parser-[0-9]*:../../devel/py-requirements-parser
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools
DEPENDS+=	${PYPKGPREFIX}-types-toml-[0-9]*:../../devel/py-types-toml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
