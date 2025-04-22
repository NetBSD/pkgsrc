# $NetBSD: Makefile,v 1.27 2025/04/22 20:31:37 wiz Exp $

DISTNAME=	oauthlib-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/oauthlib/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4.0:../../devel/py-blinker

USE_LANGUAGES=	# none

# as of 3.2.2
# 2 failed, 650 passed, 2 skipped, 7 warnings

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
