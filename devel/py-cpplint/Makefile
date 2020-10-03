# $NetBSD: Makefile,v 1.3 2020/10/03 21:49:21 adam Exp $

DISTNAME=	cpplint-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cpplint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpplint/cpplint
COMMENT=	Static code checker for C++
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures-[0-9]*:../../devel/py-testfixtures
TOOL_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

PYTHON_VERSIONED_DEPENDENCIES=	test:test zipp:test

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cpplint cpplint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
