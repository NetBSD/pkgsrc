# $NetBSD: Makefile,v 1.4 2022/07/05 10:16:35 adam Exp $

DISTNAME=	pyte-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyte/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://github.com/selectel/pyte
COMMENT=	VTXXX-compatible terminal emulator library
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
