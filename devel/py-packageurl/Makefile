# $NetBSD: Makefile,v 1.28 2025/06/10 05:22:07 wiz Exp $

DISTNAME=	packageurl_python-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packageurl-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/package-url/packageurl-python
COMMENT=	Purl aka. Package URL parser and builder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
