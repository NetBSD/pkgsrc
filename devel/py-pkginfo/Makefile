# $NetBSD: Makefile,v 1.25 2024/11/11 07:28:18 wiz Exp $

DISTNAME=	pkginfo-1.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkginfo/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://code.launchpad.net/~tseaver/pkginfo/trunk
COMMENT=	Query metadata from sdists / bdists / installed packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
