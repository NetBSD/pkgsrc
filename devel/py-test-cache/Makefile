# $NetBSD: Makefile,v 1.2 2017/09/04 18:08:22 wiz Exp $

DISTNAME=	pytest-cache-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/hpk42/pytest-cache/
COMMENT=	Pytest plugin with mechanisms for caching across test runs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execnet>=1.2:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-test>=2.2:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
