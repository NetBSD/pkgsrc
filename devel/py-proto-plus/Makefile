# $NetBSD: Makefile,v 1.17 2026/08/09 16:49:57 wiz Exp $

DISTNAME=	proto_plus-1.28.3
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

# as of 1.28.3
# 2 failed, 272 passed, 2 skipped, 12 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
