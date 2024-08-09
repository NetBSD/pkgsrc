# $NetBSD: Makefile,v 1.1 2024/08/09 11:15:14 wiz Exp $

DISTNAME=	bashlex-0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bashlex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/idank/bashlex.git
COMMENT=	Python parser for bash
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
