# $NetBSD: Makefile,v 1.7 2023/08/30 21:46:34 js Exp $

DISTNAME=	pymacaroons-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymacaroons/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Python implementation of Macaroons
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nacl>=1.1.2:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-nacl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
