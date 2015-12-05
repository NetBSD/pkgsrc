# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:43 adam Exp $

DISTNAME=	easyAI-0.0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	https://pypi.python.org/packages/source/e/easyAI/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/easyAI
COMMENT=	Easy-to-use game AI algorithms
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.0.0.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
