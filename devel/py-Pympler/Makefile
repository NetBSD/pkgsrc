# $NetBSD: Makefile,v 1.8 2024/12/26 21:43:01 adam Exp $

DISTNAME=	pympler-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pympler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pympler/pympler
COMMENT=	Python memory analysis tool
LICENSE=	apache-2.0

WHEEL_NAME=	${DISTNAME:S/^p/P/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
