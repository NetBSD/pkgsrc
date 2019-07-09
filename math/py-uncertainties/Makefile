# $NetBSD: Makefile,v 1.2 2019/07/09 23:02:29 nia Exp $

DISTNAME=	uncertainties-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncertainties/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uncertainties-python-package.readthedocs.io/
COMMENT=	Transparent calculations with uncertainties on the quantities involved
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
