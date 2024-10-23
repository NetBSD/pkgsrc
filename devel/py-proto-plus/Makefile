# $NetBSD: Makefile,v 1.6 2024/10/23 16:41:17 adam Exp $

DISTNAME=	proto_plus-1.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/proto-plus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/proto-plus-python
COMMENT=	Beautiful, Pythonic protocol buffers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.19.0:../../devel/py-protobuf
# this depends on py-proto-plus:
TEST_DEPENDS+=	${PYPKGPREFIX}-google-api-core>=1.31.5:../../devel/py-google-api-core
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
