# $NetBSD: Makefile,v 1.9 2022/07/11 08:48:48 wiz Exp $

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
TOOL_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-zipp-[0-9]*:../../archivers/py-zipp
#TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures-[0-9]*:../../wip/py-testfixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cpplint cpplint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
