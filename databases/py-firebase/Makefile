# $NetBSD: Makefile,v 1.1 2015/08/06 13:26:16 kleink Exp $

DISTNAME=	python-firebase-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/python-//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-firebase/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://ozgur.github.io/python-firebase/
COMMENT=	Python interface to Firebase's REST API
LICENSE=	mit

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
