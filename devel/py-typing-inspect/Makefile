# $NetBSD: Makefile,v 1.4 2023/05/30 09:19:45 adam Exp $

DISTNAME=	typing_inspect-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_i/-i/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing_inspect/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ilevkivskyi/typing_inspect
COMMENT=	Runtime inspection utilities for typing module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.3.0:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-mypy_extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
