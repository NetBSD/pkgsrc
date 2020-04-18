# $NetBSD: Makefile,v 1.1 2020/04/18 12:49:47 js Exp $

DISTNAME=	canonicaljson-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.6.5:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.0:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	${PYSITELIB}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
