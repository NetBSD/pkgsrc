# $NetBSD: Makefile,v 1.16 2021/04/05 08:49:57 adam Exp $

DISTNAME=	construct-2.10.66
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
