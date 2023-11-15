# $NetBSD: Makefile,v 1.31 2023/11/15 09:24:57 wiz Exp $

DISTNAME=	python-driver-3.28.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=datastax/}
GITHUB_PROJECT=	python-driver

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.28:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-geomet>=0:../../geography/py-geomet
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=	${DISTNAME:S/python-/cassandra_/}

.include "../../lang/python/pyversion.mk"

# Remove if upstream stops being obsessive about Cython version
MAKE_ENV+=	CASS_DRIVER_ALLOWED_CYTHON_VERSION=0.*

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
