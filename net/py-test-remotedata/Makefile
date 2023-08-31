# $NetBSD: Makefile,v 1.1 2023/08/31 13:56:46 adam Exp $

DISTNAME=	pytest-remotedata-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-remotedata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/pytest-remotedata
COMMENT=	Pytest plugin for controlling remote data access
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
