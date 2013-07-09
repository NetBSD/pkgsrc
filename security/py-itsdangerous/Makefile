# $NetBSD: Makefile,v 1.2 2013/07/09 16:49:16 kleink Exp $

DISTNAME=	itsdangerous-0.22
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
