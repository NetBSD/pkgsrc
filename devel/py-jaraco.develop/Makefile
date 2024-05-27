# $NetBSD: Makefile,v 1.5 2024/05/27 09:06:06 adam Exp $

DISTNAME=	jaraco_develop-8.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.develop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.develop
COMMENT=	Development utilities by jaraco
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/_/./}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-autocommand-[0-9]*:../../misc/py-autocommand
DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
DEPENDS+=	${PYPKGPREFIX}-jaraco.collections-[0-9]*:../../devel/py-jaraco.collections
DEPENDS+=	${PYPKGPREFIX}-jaraco.context-[0-9]*:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.packaging>=10:../../devel/py-jaraco.packaging
DEPENDS+=	${PYPKGPREFIX}-jaraco.vcs>=1.1:../../devel/py-jaraco.vcs
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-ini2toml-[0-9]*:../../textproc/py-ini2toml
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-path-[0-9]*:../../devel/py-path
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-subprocess-tee-[0-9]*:../../sysutils/py-subprocess-tee
# TODO: not yet imported
#DEPENDS+=	${PYPKGPREFIX}-jaraco.ui-[0-9]*
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
