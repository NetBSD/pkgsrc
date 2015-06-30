# $NetBSD: Makefile,v 1.2 2015/06/30 22:44:17 rodent Exp $
#

DISTNAME=	limits-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/l/limits/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://limits.readthedocs.org/
COMMENT=	Rate limiting utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
