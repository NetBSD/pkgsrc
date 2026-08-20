# $NetBSD: Makefile,v 1.8 2026/08/20 05:24:04 adam Exp $

DISTNAME=	zipstream_ng-1.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipstream-ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pR0Ps/zipstream-ng
COMMENT=	Modern and easy to use streamable zip file generator
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
REPLACE_PYTHON=		src/zipstream/server.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
