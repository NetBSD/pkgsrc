# $NetBSD: Makefile,v 1.2 2019/02/25 08:47:37 adam Exp $

DISTNAME=	pytest-xprocess-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xprocess
COMMENT=	Pytest plugin to manage external processes across test runs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-test>=2.3.5:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-cache-[0-9]*:../../devel/py-test-cache

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
