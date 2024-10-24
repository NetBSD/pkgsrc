# $NetBSD: Makefile,v 1.2 2024/10/24 06:48:23 adam Exp $

DISTNAME=	cloudpickle-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloudpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cloudpipe/cloudpickle
COMMENT=	Extend the standard pickle.Pickler functionality
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.9:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>0:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
