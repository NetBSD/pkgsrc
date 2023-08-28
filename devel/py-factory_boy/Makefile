# $NetBSD: Makefile,v 1.7 2023/08/28 09:39:51 adam Exp $

DISTNAME=	factory_boy-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/factory_boy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FactoryBoy/factory_boy
COMMENT=	Versatile test fixtures replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-faker>=0.7.0:../../devel/py-faker

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
