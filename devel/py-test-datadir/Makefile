# $NetBSD: Makefile,v 1.1 2023/05/05 09:46:20 wiz Exp $

DISTNAME=	pytest-datadir-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datadir/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gabrielcnr/pytest-datadir
COMMENT=	Pytest plugin for test data directories and files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.10:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
