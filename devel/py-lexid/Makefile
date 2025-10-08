# $NetBSD: Makefile,v 1.3 2025/10/08 21:38:52 wiz Exp $

DISTNAME=	lexid-2021.1006
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lexid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbarkhau/lexid
COMMENT=	Variable width build numbers with lexical ordering
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-lib3to6-[0-9]*:../../devel/py-lib3to6

PYTHON_VERSIONS_INCOMPATIBLE+=	314 # py-lib3to6

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
