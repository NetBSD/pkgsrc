# $NetBSD: Makefile,v 1.24 2025/04/22 19:57:40 wiz Exp $

DISTNAME=	ConfigArgParse-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
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

WHEEL_NAME=	${DISTNAME:tl}

# as of 1.7
# 6 failed, 1887 passed, 1 skipped, 1 warning

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
