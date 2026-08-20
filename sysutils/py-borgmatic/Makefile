# $NetBSD: Makefile,v 1.2 2026/08/20 05:36:38 adam Exp $

DISTNAME=	borgmatic-2.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/borgmatic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://torsion.org/borgmatic/
COMMENT=	Configuration-driver backup software
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>0.15.0:../../devel/py-ruamel-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0:../../devel/py-flexmock

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
