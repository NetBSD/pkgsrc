# $NetBSD: Makefile,v 1.4 2025/04/12 07:43:08 adam Exp $

DISTNAME=	domdf_python_tools-3.8.0.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/domdf-python-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/domdfcoding/domdf_python_tools
COMMENT=	Helpful functions for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-natsort>=7.0.1:../../textproc/py-natsort
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.1:../../devel/py-typing-extensions
#TEST_DEPENDS+=	${PYPKGPREFIX}-coincidence

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
