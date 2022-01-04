# $NetBSD: Makefile,v 1.18 2022/01/04 20:53:39 wiz Exp $

DISTNAME=	setuptools_trial-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_trial/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/rutsky/setuptools-trial
COMMENT=	Setuptools plugin for Twisted-based unit tests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
