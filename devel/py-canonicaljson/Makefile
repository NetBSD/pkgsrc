# $NetBSD: Makefile,v 1.12 2023/06/25 22:51:36 js Exp $

DISTNAME=	canonicaljson-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/python-canonicaljson
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.14.0:../../converters/py-simplejson

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
