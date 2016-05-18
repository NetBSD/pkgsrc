# $NetBSD: Makefile,v 1.8 2016/05/18 12:31:54 wiz Exp $

DISTNAME=	requests-toolbelt-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/e1/a4/a94c037bc72ad70441aff1403d3243510d2542ddca7759faaeffeb11aefe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/requests-toolbelt
COMMENT=	Utility belt for advanced users of python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0<3.0:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-betamax-[0-9]*:../../www/py-betamax
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
