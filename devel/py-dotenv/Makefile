# $NetBSD: Makefile,v 1.1 2020/03/21 19:41:56 adam Exp $

DISTNAME=	python-dotenv-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dotenv/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/theskumar/python-dotenv
COMMENT=	Add .env support to your django/flask apps
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-sh-[0-9]*:../../sysutils/py-sh
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
