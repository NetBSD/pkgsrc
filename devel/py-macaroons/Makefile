# $NetBSD: Makefile,v 1.6 2022/10/25 11:34:12 adam Exp $

DISTNAME=	pymacaroons-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymacaroons/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Python implementation of Macaroons
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nacl>=1.1.2:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-nacl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
