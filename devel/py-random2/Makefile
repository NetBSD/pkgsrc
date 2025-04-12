# $NetBSD: Makefile,v 1.5 2025/04/12 20:13:32 adam Exp $

DISTNAME=	random2-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/random2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/strichter/random2
COMMENT=	Python 3 compatible port of Python 2 random module
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
