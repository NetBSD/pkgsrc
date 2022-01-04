# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:08 wiz Exp $

DISTNAME=	googleapis-common-protos-1.53.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-common-protos
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.6.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=   27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
