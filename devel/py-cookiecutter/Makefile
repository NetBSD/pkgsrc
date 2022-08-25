# $NetBSD: Makefile,v 1.12 2022/08/25 20:19:57 leot Exp $

DISTNAME=	cookiecutter-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cookiecutter/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/cookiecutter
COMMENT=	Command-line utility that creates projects from project templates
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.4.4:../../devel/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jinja2-time>=0.2.0:../../time/py-jinja2-time
DEPENDS+=	${PYPKGPREFIX}-requests>=2.23.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-slugify>=4.0.0:../../devel/py-slugify
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-slugify

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cookiecutter cookiecutter-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
