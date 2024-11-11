# $NetBSD: Makefile,v 1.13 2024/11/11 07:28:05 wiz Exp $

DISTNAME=	cpplint-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cpplint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpplint/cpplint
COMMENT=	Static code checker for C++
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
# tests are broken anyway
# 196 failed, 12 passed
#TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures-[0-9]*:../../wip/py-testfixtures
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
#TEST_DEPENDS+=	${PYPKGPREFIX}-zipp-[0-9]*:../../archivers/py-zipp

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cpplint cpplint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
