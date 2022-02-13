# $NetBSD: Makefile,v 1.19 2022/02/13 08:53:43 wiz Exp $

DISTNAME=	setuptools_trial-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_trial/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/rutsky/setuptools-trial
COMMENT=	Setuptools plugin for Twisted-based unit tests
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

PYTHON_VERSIONED_DEPENDENCIES+=	twisted

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
