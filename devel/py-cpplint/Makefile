# $NetBSD: Makefile,v 1.8 2022/01/05 15:41:02 wiz Exp $

DISTNAME=	cpplint-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cpplint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpplint/cpplint
COMMENT=	Static code checker for C++
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures-[0-9]*:../../devel/py-testfixtures

PYTHON_VERSIONED_DEPENDENCIES=	pip:tool test:test zipp:test pyparsing:test

USE_PKG_RESOURCES=	yes

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
