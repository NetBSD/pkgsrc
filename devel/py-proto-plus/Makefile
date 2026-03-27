# $NetBSD: Makefile,v 1.13 2026/03/27 10:51:39 adam Exp $

DISTNAME=	proto_plus-1.27.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/proto-plus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/proto-plus
COMMENT=	Beautiful, Pythonic protocol buffers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.25.8:../../devel/py-protobuf
# this depends on py-proto-plus:
TEST_DEPENDS+=	${PYPKGPREFIX}-google-api-core>=1.31.5:../../devel/py-google-api-core
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
