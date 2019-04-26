# $NetBSD: Makefile,v 1.10 2019/04/26 13:13:50 maya Exp $

DISTNAME=	async-timeout-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/async-timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/async_timeout
COMMENT=	Timeout context manager for asyncio programs
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
