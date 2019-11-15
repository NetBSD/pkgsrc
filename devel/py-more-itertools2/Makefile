# $NetBSD: Makefile,v 1.2 2019/11/15 14:08:35 wiz Exp $

DISTNAME=	more-itertools-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/more-itertools/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/more-itertools
COMMENT=	More routines for operating on iterables, beyond itertools (for Python 2.x)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.0.0:../../lang/py-six

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
