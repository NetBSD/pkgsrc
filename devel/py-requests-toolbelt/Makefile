# $NetBSD: Makefile,v 1.2 2014/12/31 13:57:27 wiz Exp $

DISTNAME=	requests-toolbelt-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests-toolbelt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/requests-toolbelt
COMMENT=	Utility belt for advanced users of python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
