# $NetBSD: Makefile,v 1.9 2026/01/08 10:21:24 adam Exp $

DISTNAME=	asdf_standard-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf-standard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asdf-format/asdf-standard
COMMENT=	ASDF Standard schemas
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf>=3.0.0:../../math/py-asdf
# TODO: ${PYPKGPREFIX}-test-asdf-plugin
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=16.0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
