# $NetBSD: Makefile,v 1.16 2020/06/17 06:48:17 adam Exp $

DISTNAME=	more-itertools-8.4.0
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
