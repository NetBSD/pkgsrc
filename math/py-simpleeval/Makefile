# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:49 adam Exp $

DISTNAME=	simpleeval-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/s/simpleeval/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/danthedeckie/simpleeval
COMMENT=	Simple, safe single expression evaluator library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
