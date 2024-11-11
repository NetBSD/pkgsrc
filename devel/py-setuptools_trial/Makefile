# $NetBSD: Makefile,v 1.22 2024/11/11 07:28:23 wiz Exp $

DISTNAME=	setuptools_trial-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_trial/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/rutsky/setuptools-trial
COMMENT=	Setuptools plugin for Twisted-based unit tests
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

PYTHON_VERSIONS_INCOMPATIBLE=	27

# test status as of 0.6.0
# with Python 3.11:
# 2 failed
# with Python 3.12:
# uses deprecated 'imp' module which was removed in Python 3.12

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
