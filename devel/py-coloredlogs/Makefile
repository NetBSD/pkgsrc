# $NetBSD: Makefile,v 1.2 2023/07/23 02:01:25 wiz Exp $

DISTNAME=	coloredlogs-15.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coloredlogs/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/coloredlogs/
COMMENT=	Colored terminal output for Python's logging module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=9.1:../../textproc/py-humanfriendly

TEST_DEPENDS+=	${PYPKGPREFIX}-capturer>=2.4:../../devel/py-capturer
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.3.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-verboselogs>=1.7:../../devel/py-verboselogs

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
