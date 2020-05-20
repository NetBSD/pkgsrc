# $NetBSD: Makefile,v 1.2 2020/05/20 07:04:37 wiz Exp $

DISTNAME=	factory_boy-2.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/factory_boy/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/FactoryBoy/factory_boy
COMMENT=	Versatile test fixtures replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-faker>=0.7.0:../../devel/py-faker

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-faker

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
