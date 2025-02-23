# $NetBSD: Makefile,v 1.13 2025/02/23 18:35:35 wiz Exp $

DISTNAME=	itsdangerous-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itsdangerous/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/itsdangerous/
COMMENT=	Helpers to pass trusted data to untrusted environments and back
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
