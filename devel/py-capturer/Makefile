# $NetBSD: Makefile,v 1.1 2023/07/22 12:33:55 bacon Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
