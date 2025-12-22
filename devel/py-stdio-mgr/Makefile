# $NetBSD: Makefile,v 1.2 2025/12/22 06:18:07 adam Exp $

DISTNAME=	stdio_mgr-1.0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stdio-mgr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.github.com/bskinn/stdio-mgr
COMMENT=	Context manager for mocking/wrapping stdin/stdout/stderr
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.1:../../devel/py-attrs

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
