# $NetBSD: Makefile,v 1.4 2022/01/04 20:52:55 wiz Exp $

DISTNAME=	canonicaljson-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/canonicaljson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Encodes objects and arrays as RFC 7159 JSON
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.14.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.0:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	${PYSITELIB}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
