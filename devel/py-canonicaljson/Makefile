# $NetBSD: Makefile,v 1.11 2023/02/21 06:09:35 adam Exp $

DISTNAME=	canonicaljson-1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/python-canonicaljson
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.0:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.14.0:../../converters/py-simplejson

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-frozendict

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
