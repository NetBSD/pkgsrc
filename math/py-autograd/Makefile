# $NetBSD: Makefile,v 1.5 2021/06/29 08:42:00 nia Exp $

DISTNAME=	autograd-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autograd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HIPS/autograd
COMMENT=	Efficiently computes derivatives of numpy code
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE+=	36	# py-numpy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
