# $NetBSD: Makefile,v 1.1 2026/11/09 08:04:18 wiz Exp $

DISTNAME=	py_cpuinfo2-10.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py_cpuinfo2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akx/py-cpuinfo2
COMMENT=	Get CPU info with pure Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

# as of 10.1.1
# 1 failed, 163 passed, 2 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
