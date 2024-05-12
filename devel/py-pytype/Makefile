# $NetBSD: Makefile,v 1.1 2024/05/12 17:48:08 wiz Exp $

DISTNAME=	pytype-2024.4.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytype/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://google.github.io/pytype
COMMENT=	static type analyzer for Python code
LICENSE=	mit AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-dot>=1.4.2:../../graphics/py-dot
DEPENDS+=	${PYPKGPREFIX}-immutabledict>=4.1.0:../../devel/py-immutabledict
DEPENDS+=	${PYPKGPREFIX}-importlab>=0.8:../../devel/py-importlab
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-libcst>=1.0.1:../../lang/py-libcst
DEPENDS+=	${PYPKGPREFIX}-msgspec>=0.18.6:../../devel/py-msgspec
DEPENDS+=	${PYPKGPREFIX}-ninja>=1.10.1:../../devel/py-ninja
DEPENDS+=	${PYPKGPREFIX}-pycnite>=2023.10.11:../../devel/py-pycnite
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.8.10:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for file in annotate-ast merge-pyi pytd pytype pytype-single pyxref
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
