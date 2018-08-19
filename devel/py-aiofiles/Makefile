# $NetBSD: Makefile,v 1.3 2018/08/19 11:16:25 adam Exp $

DISTNAME=	aiofiles-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiofiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Tinche/aiofiles
COMMENT=	File support for asyncio
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
