# $NetBSD: Makefile,v 1.7 2025/02/23 19:33:50 wiz Exp $

DISTNAME=	threadpoolctl-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/threadpoolctl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joblib/threadpoolctl
COMMENT=	Helpers to limit the number of threads used
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
