# $NetBSD: Makefile,v 1.5 2026/06/01 19:42:52 adam Exp $

DISTNAME=	invoke-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/invoke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pyinvoke.org/
COMMENT=	Pythonic task execution
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream>=2.1:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=2:../../devel/py-test-relaxed

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	inv invoke

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
