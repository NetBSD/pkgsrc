# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:33 wiz Exp $

DISTNAME=	easyAI-0.0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easyAI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/easyAI
COMMENT=	Easy-to-use game AI algorithms
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.0.0.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
