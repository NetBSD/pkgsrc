# $NetBSD: Makefile,v 1.6 2021/06/29 08:42:01 nia Exp $

DISTNAME=	patsy-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patsy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/patsy
COMMENT=	Python package for describing statistical models
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE+=	36	# py-numpy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
