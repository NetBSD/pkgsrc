# $NetBSD: Makefile,v 1.1 2017/04/04 13:47:09 wiz Exp $

DISTNAME=	mando-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mando/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://mando.readthedocs.org/
COMMENT=	Create Python CLI apps with little to no effort at all
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-ParamUnittest-[0-9]*:../../devel/py-ParamUnittest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
