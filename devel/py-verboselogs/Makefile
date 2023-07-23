# $NetBSD: Makefile,v 1.2 2023/07/23 02:07:36 wiz Exp $

DISTNAME=	verboselogs-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/verboselogs/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/verboselogs/
COMMENT=	Extend Python logging module to add the log levels
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.6.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.2.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-astroid>0:../../devel/py-astroid
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>0:../../devel/py-pylint

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
