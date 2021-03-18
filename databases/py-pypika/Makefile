# $NetBSD: Makefile,v 1.17 2021/03/18 06:29:10 adam Exp $

DISTNAME=	PyPika-0.48.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyPika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kayak/pypika
COMMENT=	SQL query builder API for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
