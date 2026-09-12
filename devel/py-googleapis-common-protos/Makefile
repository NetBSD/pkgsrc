# $NetBSD: Makefile,v 1.33 2026/09/12 20:57:18 wiz Exp $

DISTNAME=	googleapis_common_protos-1.75.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.6:../../devel/py-protobuf
# would lead to dependency cycle
#TEST_DEPENDS+=	${PYPKGPREFIX}-google-api-core>=0:../../devel/py-google-api-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
