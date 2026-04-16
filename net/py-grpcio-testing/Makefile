# $NetBSD: Makefile,v 1.70 2026/04/16 09:58:01 adam Exp $

DISTNAME=	grpcio_testing-1.80.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	gRPC Python testing package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=6.31.1:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
