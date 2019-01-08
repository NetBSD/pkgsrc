# $NetBSD: Makefile,v 1.8 2019/01/08 09:17:37 adam Exp $

DISTNAME=	pkginfo-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkginfo/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://code.launchpad.net/~tseaver/pkginfo/trunk
COMMENT=	Query metadatdata from sdists / bdists / installed packages
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
