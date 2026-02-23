# $NetBSD: Makefile,v 1.24 2026/02/23 08:39:55 adam Exp $

DISTNAME=	typeguard-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typeguard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/typeguard
COMMENT=	Python run-time type checking library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.2.0:../../lang/py-mypy

USE_LANGUAGES=	# none

pre-test:
	${LN} -sf ${PREFIX}/bin/mypy-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/mypy

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
