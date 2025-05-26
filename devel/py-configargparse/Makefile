# $NetBSD: Makefile,v 1.25 2025/05/26 05:18:16 adam Exp $

DISTNAME=	configargparse-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/ConfigArgParse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bw2/ConfigArgParse
COMMENT=	Argparse-like with config files or environment variables support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

# as of 1.7
# 6 failed, 1887 passed, 1 skipped, 1 warning

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
