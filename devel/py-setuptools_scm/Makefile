# $NetBSD: Makefile,v 1.40 2024/05/14 08:08:31 wiz Exp $

DISTNAME=	setuptools_scm-8.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=45:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
