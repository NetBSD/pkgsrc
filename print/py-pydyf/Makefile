# $NetBSD: Makefile,v 1.10 2024/03/03 15:29:19 adam Exp $

DISTNAME=	pydyf-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydyf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.courtbouillon.org/pydyf
COMMENT=	Low-level PDF generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
TEST_DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${CHMOD} -x ${WRKSRC}/pydyf/__init__.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
