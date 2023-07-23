# $NetBSD: Makefile,v 1.3 2023/07/23 02:02:30 wiz Exp $

DISTNAME=	capturer-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/capturer/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/capturer/
COMMENT=	Easily capture stdout/stderr of the current process and subprocesses
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=8.0:../../textproc/py-humanfriendly

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.4.0:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
