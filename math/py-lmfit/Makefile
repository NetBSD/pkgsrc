# $NetBSD: Makefile,v 1.1 2016/09/16 15:20:31 prlw1 Exp $

DISTNAME=	lmfit-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmfit/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://pypi.python.org/pypi/lmfit/
COMMENT=	Least-squares minimization with bounds and constraints
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
