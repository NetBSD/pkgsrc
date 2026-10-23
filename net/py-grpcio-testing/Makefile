# $NetBSD: Makefile,v 1.77 2026/10/23 07:57:42 adam Exp $

DISTNAME=	grpcio_testing-1.84.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	gRPC Python testing package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=7.35.1:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
