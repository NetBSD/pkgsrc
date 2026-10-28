# $NetBSD: Makefile,v 1.15 2026/10/28 08:49:34 adam Exp $

DISTNAME=	pydyf-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydyf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.courtbouillon.org/pydyf
COMMENT=	Low-level PDF generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	ghostscript-agpl>=0:../../print/ghostscript-agpl
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow>=0:../../graphics/py-Pillow

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -x ${WRKSRC}/pydyf/__init__.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
