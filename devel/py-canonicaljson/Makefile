# $NetBSD: Makefile,v 1.6 2022/01/30 10:54:26 wiz Exp $

DISTNAME=	canonicaljson-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.0:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.14.0:../../converters/py-simplejson

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-frozendict

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
