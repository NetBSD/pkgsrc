# $NetBSD: Makefile,v 1.19 2022/02/22 08:39:25 adam Exp $

DISTNAME=	construct-2.10.68
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
