# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:56 wiz Exp $

DISTNAME=	python-olm-3.2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-olm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.matrix.org/matrix-org/olm/
COMMENT=	Olm bindings for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../security/olm/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
