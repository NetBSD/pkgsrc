# $NetBSD: Makefile,v 1.5 2017/09/17 13:35:03 adam Exp $

DISTNAME=	limits-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/limits/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://limits.readthedocs.org/
COMMENT=	Rate limiting utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
