# $NetBSD: Makefile,v 1.4 2022/01/11 08:56:21 adam Exp $

DISTNAME=	aiounittest-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiounittest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kwarunek/aiounittest
COMMENT=	Test asyncio code more easily
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
