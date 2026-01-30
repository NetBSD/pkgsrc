# $NetBSD: Makefile,v 1.1 2026/01/30 12:59:38 adam Exp $

DISTNAME=	psleak-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psleak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psleak
COMMENT=	Detect memory and resource leaks in Python C extensions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-psutil>=7.2.1:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-instafail-[0-9]*:../../devel/py-test-instafail

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
