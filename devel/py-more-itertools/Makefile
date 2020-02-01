# $NetBSD: Makefile,v 1.14 2020/02/01 20:59:25 adam Exp $

DISTNAME=	more-itertools-8.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/more-itertools/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/more-itertools
COMMENT=	More routines for operating on iterables, beyond itertools
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
