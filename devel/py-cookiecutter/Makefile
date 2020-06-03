# $NetBSD: Makefile,v 1.7 2020/06/03 16:40:09 adam Exp $

DISTNAME=	cookiecutter-1.7.2
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
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-poyo>=0.5.0:../../textproc/py-poyo
DEPENDS+=	${PYPKGPREFIX}-requests>=2.23.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-slugify>=4.0.0:../../devel/py-slugify
DEPENDS+=	${PYPKGPREFIX}-whichcraft>=0.4.0:../../devel/py-whichcraft
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cookiecutter cookiecutter-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
