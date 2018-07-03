# $NetBSD: Makefile,v 1.8 2018/07/03 05:03:18 adam Exp $

DISTNAME=	easyAI-1.0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easyAI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/easyAI
COMMENT=	Easy-to-use game AI algorithms
LICENSE=	mit

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.0.0.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
