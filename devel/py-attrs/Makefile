# $NetBSD: Makefile,v 1.35 2026/10/16 17:38:11 adam Exp $

DISTNAME=	attrs-26.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/attrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-attrs/attrs
COMMENT=	Attributes without boilerplate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=23.2.0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
# tests are doomed because py-test and py-hypothesis depend on py-attrs
#TEST_DEPENDS+=	${PYPKGPREFIX}-Pympler>=0:../../devel/py-Pympler
#TEST_DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=0:../../wip/py-cloudpickle
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
#TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.1.1:../../lang/py-mypy
#TEST_DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.3:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
