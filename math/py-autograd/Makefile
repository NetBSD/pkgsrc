# $NetBSD: Makefile,v 1.2 2017/10/08 20:22:46 adam Exp $

DISTNAME=	autograd-1.1.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autograd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HIPS/autograd
COMMENT=	Efficiently computes derivatives of numpy code
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.12:../../math/py-numpy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
