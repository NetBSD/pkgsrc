# $NetBSD: Makefile,v 1.9 2022/09/29 19:41:30 adam Exp $

DISTNAME=	eth-typing-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-typing/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-typing
COMMENT=	Common type annotations for ethereum python packages
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
