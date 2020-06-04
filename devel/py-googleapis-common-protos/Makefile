# $NetBSD: Makefile,v 1.2 2020/06/04 06:20:07 adam Exp $

DISTNAME=	googleapis-common-protos-1.52.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-common-protos
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.6.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
