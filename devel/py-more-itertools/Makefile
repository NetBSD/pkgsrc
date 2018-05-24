# $NetBSD: Makefile,v 1.8 2018/05/24 07:14:37 adam Exp $

DISTNAME=	more-itertools-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/more-itertools/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/more-itertools
COMMENT=	More routines for operating on iterables, beyond itertools
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.0.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
