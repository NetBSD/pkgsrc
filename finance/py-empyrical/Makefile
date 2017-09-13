# $NetBSD: Makefile,v 1.1 2017/09/13 16:10:21 minskim Exp $

DISTNAME=	empyrical-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_PYPI:=e/empyrical/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/empyrical
COMMENT=	Common financial risk and performance metrics
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-bottleneck-[0-9]*:../../math/py-bottleneck
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
