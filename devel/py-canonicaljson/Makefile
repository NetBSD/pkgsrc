# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:03 wiz Exp $

DISTNAME=	canonicaljson-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/python-canonicaljson
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.14.0:../../converters/py-simplejson

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
