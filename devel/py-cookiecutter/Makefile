# $NetBSD: Makefile,v 1.17 2024/02/22 08:43:55 adam Exp $

DISTNAME=	cookiecutter-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cookiecutter/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/cookiecutter
COMMENT=	Command-line utility that creates projects from project templates
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.4.4:../../devel/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.23.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-slugify>=4.0.0:../../devel/py-slugify
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cookiecutter cookiecutter-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
