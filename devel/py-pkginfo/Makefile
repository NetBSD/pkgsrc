# $NetBSD: Makefile,v 1.17 2022/07/20 08:35:02 adam Exp $

DISTNAME=	pkginfo-1.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkginfo/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://code.launchpad.net/~tseaver/pkginfo/trunk
COMMENT=	Query metadata from sdists / bdists / installed packages
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
