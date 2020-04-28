# $NetBSD: Makefile,v 1.8 2020/04/28 13:23:38 adam Exp $

DISTNAME=	limits-1.5.1
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
