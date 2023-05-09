# $NetBSD: Makefile,v 1.2 2023/05/09 16:58:40 wiz Exp $

DISTNAME=	pytest-console-scripts-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-console-scripts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvas-it/pytest-console-scripts
COMMENT=	Pytest plugin for testing console scripts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=4.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		tests
SUBST_STAGE.tests=	pre-configure
SUBST_MESSAGE.tests=	Fixing command name in tests.
SUBST_FILES.tests=	tests/test_run_scripts.py
SUBST_SED.tests=	-e "s,'pytest','pytest-${PYVERSSUFFIX}',g"
SUBST_SED.tests+=	-e "s,env python,env python${PYVERSSUFFIX},g"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
