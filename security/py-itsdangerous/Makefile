# $NetBSD: Makefile,v 1.12 2024/04/19 04:40:49 adam Exp $

DISTNAME=	itsdangerous-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itsdangerous/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/itsdangerous/
COMMENT=	Helpers to pass trusted data to untrusted environments and back
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
