# $NetBSD: Makefile,v 1.19 2023/02/08 10:22:48 adam Exp $

DISTNAME=	pkginfo-1.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkginfo/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://code.launchpad.net/~tseaver/pkginfo/trunk
COMMENT=	Query metadata from sdists / bdists / installed packages
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
