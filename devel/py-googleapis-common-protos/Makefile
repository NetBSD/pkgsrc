# $NetBSD: Makefile,v 1.19 2024/11/11 07:28:10 wiz Exp $

DISTNAME=	googleapis_common_protos-1.65.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-common-protos
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.6:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
