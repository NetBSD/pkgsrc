# $NetBSD: Makefile,v 1.2 2024/08/15 22:04:25 wiz Exp $

DISTNAME=	backports_strenum-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.strenum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/clbarnes/backports.strenum
COMMENT=	Base class for creating enums that are also subclasses of str
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	310 # introduced in Python 3.11

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
