# $NetBSD: Makefile,v 1.38 2023/04/27 06:31:11 wiz Exp $

DISTNAME=	grpcio-testing-1.54.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	gRPC Python testing package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.6:../../devel/py-protobuf

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
