# $NetBSD: Makefile,v 1.10 2021/12/30 13:05:39 adam Exp $

DISTNAME=	uncertainties-3.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncertainties/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uncertainties-python-package.readthedocs.io/
COMMENT=	Transparent calculations with uncertainties on the quantities involved
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-numpy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
