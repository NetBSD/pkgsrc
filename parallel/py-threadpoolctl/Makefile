# $NetBSD: Makefile,v 1.4 2024/02/14 21:31:01 adam Exp $

DISTNAME=	threadpoolctl-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/threadpoolctl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joblib/threadpoolctl
COMMENT=	Helpers to limit the number of threads used
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=2:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
