# $NetBSD: Makefile,v 1.19 2024/11/11 07:28:12 wiz Exp $

DISTNAME=	jaraco_functools-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.functools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.functools
COMMENT=	Additional functools in the spirit of stdlib's functools
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/_/./}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
