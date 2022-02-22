# $NetBSD: Makefile,v 1.12 2022/02/22 09:08:48 wiz Exp $

DISTNAME=	mccabe-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/mccabe/
COMMENT=	Mccabe plugin for the Python program checker flake8
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# https://github.com/PyCQA/mccabe/issues/93
# as of 0.7.0, tests do not run:
# NameError: name 'settings' is not defined
# probably fixed by adding hypothesmith dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith-[0-9]*:../../wip/py-hypothesmith

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
