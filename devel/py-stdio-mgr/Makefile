# $NetBSD: Makefile,v 1.1 2023/05/06 08:52:25 wiz Exp $

DISTNAME=	stdio-mgr-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stdio-mgr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.github.com/bskinn/stdio-mgr
COMMENT=	Context manager for mocking/wrapping stdin/stdout/stderr
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=17.1:../../devel/py-attrs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
