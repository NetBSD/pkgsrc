# $NetBSD: Makefile,v 1.2 2023/08/04 09:49:45 adam Exp $

DISTNAME=	pytest-mypy-plugins-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy-plugins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TypedDjango/pytest-mypy-plugins
COMMENT=	Pytest plugin for writing cmd for mypy plugins
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-mypy>=1.3:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		cmd
SUBST_STAGE.cmd=	pre-configure
SUBST_MESSAGE.cmd=	Fixing command name.
SUBST_FILES.cmd=	pytest_mypy_plugins/item.py
SUBST_SED.cmd=		-e 's,"mypy","mypy-${PYVERSSUFFIX}",g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
