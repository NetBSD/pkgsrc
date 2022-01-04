# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:40 wiz Exp $

DISTNAME=	pytest-cache-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/hpk42/pytest-cache/
COMMENT=	Pytest plugin with mechanisms for caching across test runs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execnet>=1.2:../../devel/py-execnet

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
