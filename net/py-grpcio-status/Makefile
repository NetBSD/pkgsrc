# $NetBSD: Makefile,v 1.2 2026/08/18 18:33:45 adam Exp $

DISTNAME=	grpcio_status-1.83.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-status/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Reference package for GRPC Python status proto mapping
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=0:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio

.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
