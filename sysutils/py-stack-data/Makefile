# $NetBSD: Makefile,v 1.2 2022/02/01 10:08:09 wiz Exp $

DISTNAME=	stack_data-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stack-data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexmojaki/stack_data
COMMENT=	Extract data from Python stack frames and tracebacks
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-asttokens>0:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-executing>0:../../lang/py-executing
DEPENDS+=	${PYPKGPREFIX}-pure-eval>0:../../lang/py-pure-eval
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-littleutils>0:../../devel/py-littleutils
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>0:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typeguard>0:../../devel/py-typeguard
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
