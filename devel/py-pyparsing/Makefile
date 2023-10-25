# $NetBSD: Makefile,v 1.31 2023/10/25 22:24:14 wiz Exp $

DISTNAME=	pyparsing-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyparsing/pyparsing
COMMENT=	Parsing module for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
