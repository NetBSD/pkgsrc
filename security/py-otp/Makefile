# $NetBSD: Makefile,v 1.1 2023/03/11 08:55:13 wiz Exp $

DISTNAME=	pyotp-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyotp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pyotp/pyotp
COMMENT=	Python One-Time Password Library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
