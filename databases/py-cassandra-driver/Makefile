# $NetBSD: Makefile,v 1.36 2026/02/19 08:21:09 wiz Exp $

DISTNAME=	python-driver-3.29.3
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=datastax/}
GITHUB_PROJECT=	python-driver

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.28:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-geomet>=0:../../geography/py-geomet
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

WHEEL_NAME=	${DISTNAME:S/python-/cassandra_/}

WRKSRC=		${WRKDIR}/cassandra-${DISTNAME}

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/pyversion.mk"

# Remove if upstream stops being obsessive about Cython version
MAKE_ENV+=	CASS_DRIVER_ALLOWED_CYTHON_VERSION=0.*

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
