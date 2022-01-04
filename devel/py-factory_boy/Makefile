# $NetBSD: Makefile,v 1.6 2022/01/04 20:53:03 wiz Exp $

DISTNAME=	factory_boy-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/factory_boy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FactoryBoy/factory_boy
COMMENT=	Versatile test fixtures replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-faker>=0.7.0:../../devel/py-faker

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-faker

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
