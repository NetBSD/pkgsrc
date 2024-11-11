# $NetBSD: Makefile,v 1.10 2024/11/11 07:28:26 wiz Exp $

DISTNAME=	pytest-relaxed-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-relaxed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bitprophet/pytest-relaxed
COMMENT=	Relaxed test discovery/organization for pytest
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
# Testing needs: invocations>=3.3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
