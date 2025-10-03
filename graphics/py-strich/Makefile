# $NetBSD: Makefile,v 1.9 2025/10/03 11:12:10 adam Exp $

DISTNAME=	pystrich-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.3:../../graphics/py-Pillow
TEST_DEPENDS+=	dmtx-utils-[0-9]*:../../graphics/dmtx-utils

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
