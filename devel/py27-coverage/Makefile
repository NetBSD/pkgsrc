# $NetBSD: Makefile,v 1.6 2023/10/23 06:37:43 wiz Exp $

DISTNAME=	coverage-5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

#TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
#TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7.0:../../devel/py-flaky
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.57.1:../../devel/py-hypothesis4
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test4
#TEST_DEPENDS+=	${PYPKGPREFIX}-unittest-mixins>=1.6:../../devel/py-unittest-mixins

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

PYSETUPTESTTARGET=	pytest

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage[23]

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
