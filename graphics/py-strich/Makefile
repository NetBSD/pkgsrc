# $NetBSD: Makefile,v 1.13 2026/09/04 09:43:07 adam Exp $

DISTNAME=	pystrich-0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-Pillow>=12.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.15.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	dmtx-utils>=0:../../graphics/dmtx-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.155.2:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

PY_RENAME_BINARIES=	pystrich

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
