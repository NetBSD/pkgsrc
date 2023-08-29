# $NetBSD: Makefile,v 1.21 2023/08/29 07:29:24 adam Exp $

DISTNAME=	decorator-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/decorator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/micheles/decorator
COMMENT=	Generic Python decorator utilities
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
