# $NetBSD: Makefile,v 1.10 2026/05/20 06:01:16 adam Exp $

DISTNAME=	pystrich-0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-Pillow>=12.2:../../graphics/py-Pillow
TEST_DEPENDS+=	dmtx-utils-[0-9]*:../../graphics/dmtx-utils

PY_RENAME_BINARIES=	pystrich

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
