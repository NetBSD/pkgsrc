# $NetBSD: Makefile,v 1.2 2017/08/31 08:27:42 prlw1 Exp $

DISTNAME=	lmfit-0.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmfit/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://lmfit.github.io/lmfit-py/
COMMENT=	Least-squares minimization with bounds and constraints
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.19:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
