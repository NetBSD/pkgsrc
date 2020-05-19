# $NetBSD: Makefile,v 1.1 2020/05/19 18:36:32 wiz Exp $

DISTNAME=	factory_boy-2.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/factory_boy/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/FactoryBoy/factory_boy
COMMENT=	Versatile test fixtures replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-faker>=0.7.0:../../devel/py-faker

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
