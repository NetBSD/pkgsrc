# $NetBSD: Makefile,v 1.1 2013/06/14 09:41:01 kleink Exp $

DISTNAME=	itsdangerous-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/i/itsdangerous/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/itsdangerous/
COMMENT=	Helpers to pass trusted data to untrusted environments and back
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31 32

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
