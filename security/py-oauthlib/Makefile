# $NetBSD: Makefile,v 1.29 2026/11/25 14:00:17 adam Exp $

DISTNAME=	oauthlib-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/oauthlib/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# signedtoken
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0.0:../../textproc/py-JWT
# signals
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4.0:../../devel/py-blinker

USE_LANGUAGES=	# none

# as of 3.3.1
# 681 passed, 2 skipped, 6 warnings

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
