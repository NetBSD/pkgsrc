# $NetBSD: Makefile,v 1.11 2022/04/29 12:05:02 wiz Exp $

DISTNAME=	itsdangerous-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itsdangerous/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/itsdangerous/
COMMENT=	Helpers to pass trusted data to untrusted environments and back
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
