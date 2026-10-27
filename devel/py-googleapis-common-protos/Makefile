# $NetBSD: Makefile,v 1.36 2026/10/27 11:40:44 wiz Exp $

DISTNAME=	googleapis_common_protos-1.76.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/googleapis-common-protos
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-protobuf>=6.33.5:../../devel/py-protobuf
TEST_DEPENDS+=	${PYPKGPREFIX}-grpcio>=0:../../net/py-grpcio

USE_LANGUAGES=	# none

# test works after 'make install'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
