# $NetBSD: Makefile,v 1.2 2023/08/05 07:38:57 adam Exp $

DISTNAME=	pyotp-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyotp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pyauth/pyotp
COMMENT=	Python One-Time Password Library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
